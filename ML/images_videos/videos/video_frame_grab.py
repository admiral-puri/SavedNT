#video player with frame grab feature

import cv2

class VideoPlayer:
	def __init__(self,video_fp):
		#open the video file
		self.vhndl = cv2.VideoCapture(video_fp)

		#check for open state
		if not self.vhndl.isOpened():
			raise Exception(video_fp + 'not found')

		#find the fps to control loop delay
		self.fps = self.vhndl.get(cv2.CAP_PROP_FPS)

		#frame and loop control flag
		self.flag = False
		self.curr_frame = None

	def __del__(self):
		cv2.destroyAllWindows()

	#callback
	def mouse_event(self, event, x,y,flag, params):
		if event == cv2.EVENT_LBUTTONDOWN:
			cv2.imwrite(filename='d:/images/grab.jpg', img=self.curr_frame)
		elif event == cv2.EVENT_RBUTTONDOWN:
			copy = cv2.cvtColor(self.curr_frame, cv2.COLOR_BGR2GRAY)
			cv2.imwrite(filename='d:/images/grab_bw.jpg', img=copy)

	def play(self):
		# initialize (create a named window)
		cv2.namedWindow('BASIC_PLAYER')
		cv2.setMouseCallback('BASIC_PLAYER', self.mouse_event)
		# initialize (grab a frame)
		self.flag, self.curr_frame = self.vhndl.read()

		while self.flag:
			#render
			cv2.imshow('BASIC_PLAYER', self.curr_frame)
			#reinitialization (grab the next frame)
			self.flag,self.curr_frame = self.vhndl.read()

			#slow it down
			key_pressed = cv2.waitKey(int(1/self.fps*1000))
			if key_pressed == 27:
				break



def main():
	vp = VideoPlayer('d:/videos/idea.mp4')
	vp.play()

main()