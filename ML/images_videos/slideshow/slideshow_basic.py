#BASIC SLIDESHOW
from os import listdir
import cv2

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
	#per slide (image)
	for x in slides:
		#read the image from the source
		img = cv2.imread(source + '/'+ x)
		#resize the image to std dimension
		img = cv2.resize(img, (1280,800))
		#render the image
		cv2.imshow('SLIDESHOW', img)
		#wait for 1 second or esc to stop the slideshow
		if cv2.waitKey(1000) == 27:
			break
			
	#relase the resource
	cv2.destroyWindow('SLIDESHOW')


def main():
	slideshow()

#start here
main()

