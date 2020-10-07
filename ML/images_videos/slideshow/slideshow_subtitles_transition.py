#SLIDESHOW with subtitles and transition
from os import listdir
from PIL import Image, ImageDraw, ImageFont
import cv2
import numpy as np

#dir parsing to fetch files of specific types
def getFiles(source, types = ['.jpg', '.png', '.gif']):
	try:
		#fetch contents of the source dir or FileNotFoundError
		content = listdir(source)
		output = []
		for x in content:
			#filter the content to extract limited file types
			for y in types:
				if x.lower().endswith(y):
					output.append(x)
					break
		#return content
		return output
	except:
		#return an empty list
		return []

def slideshow(source ='d:/images'):
	#fetch the slides
	slides = getFiles(source)
	#create a named window
	cv2.namedWindow('SLIDESHOW')

	#a font of choice
	fnt = ImageFont.truetype('c:/windows/fonts/ITCKRIST.ttf',48)
	#a color of choice
	fore_color = (21,0,136) #b,g,r

	#per slide (image)
	for x in slides:
		#read the image from the source
		img = cv2.imread(source + '/'+ x)
		#resize the image to std dimension
		img = cv2.resize(img, (1280,800))

		#subtitle
		#convert numpy.ndarray to pil image
		pil_img = Image.fromarray(img)
		#get the object for drawing/writing
		pen = ImageDraw.Draw(pil_img)
		#calculate the required size
		reqd_size = pen.textsize(text=x, font=fnt)
		#decide the xy
		xy = (pil_img.size[0]- reqd_size[0])/2, pil_img.size[1]-50-reqd_size[1]
		#write
		pen.text(xy=xy, text= x, font=fnt, fill=fore_color)
		#convert back to numpy.ndarray
		img = np.array(pil_img)

		#render the image
		cv2.imshow('SLIDESHOW', img)
		#wait for 1 second or esc to stop the slideshow
		if cv2.waitKey(1000) == 27:
			break

		#transition
		for i in range(1,1280):
			img[:,1280-i,:] =0
			cv2.imshow('SLIDESHOW', img)
			cv2.waitKey(1)

	#relase the resource
	cv2.destroyWindow('SLIDESHOW')

def main():
	slideshow()

#start here
main()

