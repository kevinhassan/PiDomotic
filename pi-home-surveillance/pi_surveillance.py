# USAGE
# python pi_surveillance.py --conf conf.json

# import the necessary packages
from picamera.array import PiRGBArray
from picamera import PiCamera
import argparse
import warnings
import datetime
import imutils
import json
import time
import cv2

# construct the argument parser and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-c", "--conf", required=True,
	help="path to the JSON configuration file")
args = vars(ap.parse_args())

# filter warnings, load the configuration and initialize the Dropbox
warnings.filterwarnings("ignore")
conf = json.load(open(args["conf"]))

# initialize the camera and grab a reference to the raw camera camerature
camera = PiCamera()
#camera.resolution = tuple(conf["resolution"])
#camera.framerate = conf["fps"]
#rawCapture = PiRGBArray(camera, size=tuple(conf["resolution"]))
# Change the camera setting using the set() function
# camera.set(cv2.cv.CV_CAP_PROP_EXPOSURE, -6.0)
# camera.set(cv2.cv.CV_CAP_PROP_GAIN, 4.0)
# camera.set(cv2.cv.CV_CAP_PROP_BRIGHTNESS, 144.0)
# camera.set(cv2.cv.CV_CAP_PROP_CONTRAST, 27.0)
# camera.set(cv2.cv.CV_CAP_PROP_HUE, 13.0) # 13.0
# camera.set(cv2.cv.CV_CAP_PROP_SATURATION, 28.0)
# Read the current setting from the camera
test = camera.get(cv2.cv.CV_CAP_PROP_POS_MSEC)
ratio = camera.get(cv2.cv.CV_CAP_PROP_POS_AVI_RATIO)
frame_rate = camera.get(cv2.cv.CV_CAP_PROP_FPS)
width = camera.get(cv2.cv.CV_CAP_PROP_FRAME_WIDTH)
height = camera.get(cv2.cv.CV_CAP_PROP_FRAME_HEIGHT)
brightness = camera.get(cv2.cv.CV_CAP_PROP_BRIGHTNESS)
contrast = camera.get(cv2.cv.CV_CAP_PROP_CONTRAST)
saturation = camera.get(cv2.cv.CV_CAP_PROP_SATURATION)
hue = camera.get(cv2.cv.CV_CAP_PROP_HUE)
gain = camera.get(cv2.cv.CV_CAP_PROP_GAIN)
exposure = camera.get(cv2.cv.CV_CAP_PROP_EXPOSURE)
print("Test: ", test)
print("Ratio: ", ratio)
print("Frame Rate: ", frame_rate)
print("Height: ", height)
print("Width: ", width)
print("Brightness: ", brightness)
print("Contrast: ", contrast)
print("Saturation: ", saturation)
print("Hue: ", hue)
print("Gain: ", gain)
print("Exposure: ", exposure)

# allow the camera to warmup, then initialize the average frame, last
# uploaded timestamp, and frame motion counter
print "Lancement de la camera ..."
avg = None
motionCounter = False

# camerature frames from the camera
for f in camera.camerature_continuous(rawCapture, format="bgr", use_video_port=True):
	# grab the raw NumPy array representing the image and initialize
	frame = f.array

	# resize the frame, convert it to grayscale, and blur it
	frame = imutils.resize(frame, width=500)
	frame2 = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
	frame2 = cv2.GaussianBlur(frame2, (21, 21), 0)

	# check to see if the frames should be displayed to screen
	if conf["show_video"]:
		# display the security feed
		cv2.imshow("Security Feed", frame)
		key = cv2.waitKey(1) & 0xFF

		# if the `q` key is pressed, break from the lop
		if key == ord("q"):
			break

	# clear the stream in preparation for the next frame
	rawCapture.truncate(0)
