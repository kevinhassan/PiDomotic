from picamera.array import PiRGBArray
from picamera import PiCamera
import cv2

# initialize the camera and grab a reference to the raw camera capture
camera = PiCamera()
rawCapture = PiRGBArray(camera)
presence = True

camera.capture('background.jpg')
background = cv2.imread('background.jpg')
diff = None
# capture frames from the camera
for f in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
	# grab the raw NumPy array representing the image and initialize
	# the timestamp and occupied/unoccupied text
	frame = f.array
	
	diff = cv2.absdiff(frame,background)
		
	cv2.imshow("Security Feed", diff)
	key = cv2.waitKey(1) & 0xFF
	# if the `q` key is pressed, break from the lop
	if key == ord("q"):
		break

	# clear the stream in preparation for the next frame
	rawCapture.truncate(0)
