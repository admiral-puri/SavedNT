#Digitally signing an image to protect piracy by proving ownership

import cv2

#n: 104 ---> [011, 010, 00]
getBits = lambda n : [n >> 5, (n&0x1C)>>2, n&0x3]

#bits[011, 010, 00] ---> 104
getByte = lambda bits: (((bits[0]<<3) | bits[1])<<2)|bits[2]

# sign1   ---> sign1#########################
# sign155 ---> sign1555######################
normalize_signature = lambda sign, size= 30: sign.ljust(size, '#')

# sign1######################### ---> sign1
original_signature = lambda  sign : sign.strip('#')

#sequence generator
def embedding_points(qty= 30):
	points = []
	for i in range(qty):
		points.append((7, i))
	return points

def embed(trgt_img, src_img, sign):
	#normalize the input signature
	normalized_sign = normalize_signature(sign)

	#load the image in memory
	image = cv2.imread(src_img, cv2.IMREAD_COLOR)
	if image is None:
		print(src_img,'not found')
		return False

	#capacity check
	h, w, _ = image.shape
	img_capacity = h *w
	if img_capacity < len(normalized_sign):
		print('Insufficient Image Capacity')
		return False

	#embedding
	embed_at = embedding_points((len(normalized_sign)))
	cnt = 0

	for x,y in embed_at:
		bits = getBits(ord(normalized_sign[cnt]))
		image[x,y,2]= (image[x,y,2] & ~0x7) | bits[0]  #red band
		image[x,y,1]= (image[x,y,1] & ~0x7) | bits[1]  #green band
		image[x,y,0]= (image[x,y,0] & ~0x3) | bits[2]  #blue band
		cnt+=1

	#save back the image
	cv2.imwrite(trgt_img, image)

	return True

def extract(signed_image):
	#load the image in memory
	image = cv2.imread(signed_image, cv2.IMREAD_COLOR)
	if image is None:
		print(signed_image,'not found')
		return False

	#extraction
	embed_at = embedding_points(30)
	cnt = 0
	sign = ''
	for x,y in embed_at:
		bit1 = image[x,y,2] & 0x7 #red band
		bit2 = image[x,y,1] & 0x7 #green band
		bit3 = image[x,y,0] & 0x3 #blue band
		data = getByte([bit1,bit2, bit3])
		sign = sign + chr(data)
	#return the sign
	return original_signature(sign)

def main():
	while True:
		print('1. Embed ')
		print('2. Extract')
		print('3. Exit')
		ch = input()
		if ch == '1':
			print('Enter Source Image')
			srcImg = input()
			print('Enter Signature')
			signature = input()
			print('Enter Target Image')
			trgtImg = input()
			if embed(trgtImg, srcImg, signature):
				print('OK')
			else:
				print('ERROR')

		elif ch == '2':
			print('Enter Signed Image')
			signedImg = input()
			signature = extract(signedImg)
			print(signature)

		elif ch == '3':
			break

		else:
			print('Wrong Choice')

main()