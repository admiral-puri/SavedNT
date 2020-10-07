#Hands on Python Image Library (aka pillow)
from PIL import Image, ImageDraw, ImageFont

#create an empty canvas
size = 500, 300 #w,h
bg_color = 239,228,176  #r,g,b
canvas = Image.new('RGB', size, bg_color)

#to draw on a canvas, an ImageDraw object is required, get it.
pen = ImageDraw.Draw(canvas)

#define some attributes
dim = (50,50), (size[0]-50, size[1]-50)
fg_color = 136,0,21 #r,g,b
fill_color = 200,191,231 #r,g,b
fnt = ImageFont.truetype(font = 'c:/windows/fonts/arial.ttf', size=40)
text = 'Study of PIL'
m_text = '''Python
Image
Library'''

#write on canvas
#reqd_size = pen.textsize(text=text, font=fnt)
#pen.text(xy=((size[0]-reqd_size[0])/2,(size[1]- reqd_size[1])/2), text=text, font=fnt, fill=fg_color)
#reqd_size = pen.multiline_textsize(text=m_text, font=fnt)
#pen.multiline_text(xy=((size[0]-reqd_size[0])/2,(size[1]- reqd_size[1])/2), text=m_text, font=fnt, fill=fg_color)

#draw a line
#pen.line(xy=dim, fill=fg_color, width=10)

#draw a rectangle
#pen.rectangle(xy = dim, fill=fill_color, outline= fg_color, width= 5)

#draw an ellipse
#pen.ellipse(xy = dim, fill=fill_color, outline= fg_color, width= 5)

#draw an arc
#pen.arc(xy=dim, start=30, end= 270, fill= fg_color, width=5)

#draw a chord
#pen.chord(xy=dim, start=30, end= 270, fill= fill_color, outline= fg_color ,width=5)

#draw a pieslice
pen.pieslice(xy=dim, start=30, end= 270, fill= fill_color, outline= fg_color ,width=5)

#save the canvas
canvas.save('d:/images/pil_hands_on.jpg')




