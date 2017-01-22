from picamera.array import PiRGBArray
from picamera import PiCamera
import cv2
import numpy as np

# initialize the camera and grab a reference to the raw camera capture
camera = PiCamera()
rawCapture = PiRGBArray(camera)
presence = True

camera.capture('background.jpg')
background = cv2.imread('background.jpg')
cv2.GaussianBlur(background,(5,5),0)
diff = None
gray = None
thresh = None
kernel = np.ones((10,10),np.uint8)

# capture frames from the camera
for f in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
	# grab the raw NumPy array representing the image and initialize
	# the timestamp and occupied/unoccupied text
	frame = f.array
	cv2.GaussianBlur(frame,(5,5),0)
	diff = cv2.absdiff(frame,background)
	gray = cv2.cvtColor(diff,cv2.COLOR_BGR2GRAY)
	cv2.threshold(gray,50,255,cv2.THRESH_BINARY,gray)
	erosion = cv2.erode(gray,kernel,iterations = 3)
	dilate = cv2.dilate(erosion,kernel,iterations = 3)
	contours,hierarchy = cv2.findContours(dilate,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
	for j in contours:
		cnt=j
		x,y,w,h = cv2.boundingRect(cnt)
		cv2.rectangle(gray,(x,y),(x+w,y+h),(0,255,0),2)
	
	cv2.imshow("Security Feed", dilate)
	key = cv2.waitKey(1) & 0xFF
	# if the `q` key is pressed, break from the lop
	if key == ord("q"):
		break

	# clear the stream in preparation for the next frame
	rawCapture.truncate(0)
