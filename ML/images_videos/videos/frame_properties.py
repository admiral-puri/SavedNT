#fetching the frame properties of a video

import cv2

video_fp = 'd:/videos/idea.mp4'
vhndl = cv2.VideoCapture(video_fp)
if vhndl.isOpened():
	print('frame height', vhndl.get(cv2.CAP_PROP_FRAME_HEIGHT))
	print('frame width', vhndl.get(cv2.CAP_PROP_FRAME_WIDTH))
	print('frame count', vhndl.get(cv2.CAP_PROP_FRAME_COUNT))
	print('frames per sec', vhndl.get(cv2.CAP_PROP_FPS))
else:
	print(video_fp,'not found')