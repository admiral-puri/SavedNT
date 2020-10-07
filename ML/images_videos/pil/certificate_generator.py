#Certificate Generator

from PIL import Image, ImageDraw, ImageFont
from datetime import datetime

def generateCertificate(name, course, resultant_fn):
	#load the captcha background
	bg_file = 'd:/images/blank.png'
	canvas = Image.open(fp=bg_file)
	#size (w,h): canvas.size

	#to draw on a canvas, an ImageDraw object is required, get it.
	pen = ImageDraw.Draw(canvas)

	#define some attributes
	fg_color = 136,0,21 #r,g,b
	fnt = ImageFont.truetype(font = 'c:/windows/fonts/arial.ttf', size=40)
	name_center = 750,645
	course_center = 750,810

	#lets fetch system date-time
	now = datetime.now()
	# print(now.strftime('%H:%M:%S'))
	# print(now.strftime('%A %a'))
	# print(now.strftime('%B %b'))
	# print(now.strftime('%d-%m-%y'))
	# print(now.strftime('%d-%m-%Y'))
	month = now.strftime('%b')
	year = now.strftime('%Y')
	day = now.strftime('%d')

	#write on canvas
	reqd_size = pen.textsize(text=name, font=fnt)
	pen.text(xy=(name_center[0]-reqd_size[0]/2, name_center[1]- reqd_size[1]), text=name, font=fnt, fill=fg_color)

	reqd_size = pen.textsize(text=course, font=fnt)
	pen.text(xy=(course_center[0] - reqd_size[0] / 2, course_center[1] - reqd_size[1]), text=course, font=fnt, fill=fg_color)

	pen.text(xy=(460, 895), text=month, font=fnt, fill=fg_color)
	pen.text(xy=(310, 895), text=day, font=fnt, fill=fg_color)
	pen.text(xy=(585, 895), text=year, font=fnt, fill=fg_color)

	#save the canvas
	canvas.save(resultant_fn)

generateCertificate(name='Python Student', course= 'Python Image Library', resultant_fn = 'd:/images/cert_new.png')

