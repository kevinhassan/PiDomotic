#include <math.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/videoio/videoio.hpp"


using namespace cv;
using namespace std;

/* Global variables*/
const char* window_title = "capture-camera";


int main( int argc, char** argv)
{
  VideoCapture capture;
  Mat frame;
  capture.open(0); //open default camera

  //If camera doesn't work we print and return an error
  if (!capture.isOpened()){
    printf("Error opening video capture ! \n");
    return -1;
  }
  namedWindow(window_title,CV_WINDOW_AUTOSIZE);

  while(capture.read(frame)){
    imshow(window_title, frame);
    if(waitKey(30) >= 0) break; //press any key to exit
  }
  destroyWindow(window_title) ;
  return 0;
}
