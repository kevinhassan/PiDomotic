#include <ctime>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>
#include <opencv/highgui.h>
#include <unistd.h>
using namespace std;

int main ( int argc,char **argv ) {
    const char* window_title = "Raspicam ";
    cvNamedWindow (window_title, CV_WINDOW_AUTOSIZE);
    
    IplImage* frame;
    raspicam::RaspiCam Camera; //Camera object

    //Open camera
    cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {
      cerr<<"Error opening camera"<<endl;
      return -1;
    }
    //wait a while until camera stabilizes
    cout<<"Wait 3 seconde until camera stabilizes"<<endl;
    sleep(3);
    while(1){
      frame = Camera.grab();
      if( !frame ) break;
      cvShowImage( window_title, frame );
      char c = cvWaitKey(33);
      if( c == 27 ) break;
    }
    cvReleaseCapture( &Camera );
    cvDestroyWindow(window_title);
    return 0;
}
