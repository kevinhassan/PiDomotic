#include <ctime>
#include <iostream>
#include <cstdlib>
#include "raspicam/raspicam_cv.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>
using namespace std; 


int width = 2592;
int height = 1944;
 
int main ( int argc,char **argv ) {
	raspicam::RaspiCam_Cv Camera;
	cv::Mat image;
	cv::namedWindow("Raspicam", cv::WINDOW_AUTOSIZE);
	cout<<"Press any key to close the window"<<endl;
	Camera.set(CV_CAP_PROP_FRAME_WIDTH,width);
	Camera.set(CV_CAP_PROP_FRAME_HEIGHT,height);
	Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );
	cout<<"Capturing..."<<endl;
    	if ( !Camera.open ( ) ) {
	
        	cerr<<"Error opening the camera"<<endl;
        	return -1;
    	}
	while(1){
		Camera.grab();
		Camera.retrieve(image);
		//stop camera when any key is pressed
		if(cv::waitKey(0)){
			break;
		}
		
	}
	cout<<"Stop camera..."<<endl;
	Camera.release();
	return 0;
}
 
