#video player with motion tracking

import cv2

class VideoPlayer:
	def __init__(self,video_fp=0):
		#open the video file
		self.vhndl = cv2.VideoCapture(video_fp)

		#check for open state
		if not self.vhndl.isOpened():
			raise Exception(video_fp + 'not found')

		#find the fps to control loop delay
		self.fps = self.vhndl.get(cv2.CAP_PROP_FPS)

		#frame and loop control flag
		self.flag = False
		self.prev_frame = None
		self.curr_frame = None
		self.next_frame = None

	def __del__(self):
		cv2.destroyAllWindows()

	def frame_difference(self):
		diff1 = cv2.absdiff(self.next_frame, self.curr_frame)
		diff2 = cv2.absdiff(self.curr_frame, self.prev_frame)
		return cv2.bitwise_and(diff1, diff2)

	def play(self):
		# initialize (create a named window)
		cv2.namedWindow('BASIC_PLAYER')
		cv2.namedWindow('MOTION_TRACKER')

		# initialize (grab 3 frames)
		_, self.prev_frame = self.vhndl.read()
		_, self.curr_frame = self.vhndl.read()
		self.flag, self.next_frame = self.vhndl.read()

		while self.flag:
			#render
			cv2.imshow('BASIC_PLAYER', self.next_frame)
			cv2.imshow('MOTION_TRACKER', self.frame_difference())

			#reinitialization (grab the next frame)
			self.prev_frame = self.curr_frame
			self.curr_frame = self.next_frame
			self.flag,self.next_frame = self.vhndl.read()

			#slow it down
			key_pressed = cv2.waitKey(int(1/self.fps*1000))
			if key_pressed == 27:
				break


def main():
	vp = VideoPlayer('d:/videos/follower.mp4')
	vp.play()

main()