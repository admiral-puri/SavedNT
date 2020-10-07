#basic video player

import cv2

def video_renderer(video_fp):
	#open the video file
	vhndl = cv2.VideoCapture(video_fp)

	#check for open state
	if not vhndl.isOpened():
		print(video_fp,'not found')
		return

	#find the fps to control loop delay
	fps = vhndl.get(cv2.CAP_PROP_FPS)

	#initialize (create a named window)
	cv2.namedWindow('BASIC_PLAYER')
	#initialize (grab a frame)
	flag,curr_frame = vhndl.read()
	while flag:
		#render
		cv2.imshow('BASIC_PLAYER', curr_frame)

		#reinitialization (grab the next frame)
		flag,curr_frame = vhndl.read()
		
		#slow it down
		key_pressed = cv2.waitKey(int(1/fps*1000))
		if key_pressed == 27:
			break

	cv2.destroyAllWindows()


video_renderer('d:/videos/idea.mp4')