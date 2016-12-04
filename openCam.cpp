#include <ctime>
#include <iostream>
#include <cstdlib>
#include "raspicam/raspicam_cv.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>
using namespace std; 
using namespace cv;


int width = 2592;
int height = 1944;
const char * window_title = "Raspicam-Test"; 
int main ( int argc,char **argv ) {
	raspicam::RaspiCam_Cv Camera;
	Mat frame;
	namedWindow(window_title, cv::WINDOW_AUTOSIZE);
	cout<<"Press any key to close the window"<<endl;
	Camera.set(CV_CAP_PROP_FRAME_WIDTH,width);
	Camera.set(CV_CAP_PROP_FRAME_HEIGHT,height);
	cout<<"Capturing..."<<endl;
    	Camera.open();
	if ( !Camera.isOpened ( ) ) {
	
        	cerr<<"Error opening the camera"<<endl;
        	return -1;
    	}
	while(1){
		if(!Camera.grab()){
			cerr<<"Error can not grab images"<<endl;
		}else{
			Camera.retrieve(frame);
			imshow(window_title, frame);
			//stop camera when any key is pressed
			if(waitKey(0)){
				break;
			}
		}
	}
	cout<<"Stop camera..."<<endl;
	cvDestroyWindow(window_title);
	Camera.release();
	return 0;
}
 
