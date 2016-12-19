#include <math.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/videoio/videoio.hpp"


using namespace cv;
using namespace std;


int main( int argc, char** argv)
{
  const char* window_title = "capture-camera";
  VideoCapture cap(0); // open the default camera
  if(!cap.isOpened())  // check if we succeeded
    return -1;

  Mat edges;
  namedWindow(window_title,CV_WINDOW_AUTOSIZE);
  while(1){
    Mat frame;
    cap >> frame;
    imshow(window_title, frame);
    if(waitKey(30) >= 0) break; //press any key to exit
  }
  destroyWindow(window_title) ;
  return 0;
}
