#include <math.h>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/utility.hpp"


using namespace cv;
using namespace std;


int main( int argc, char** argv)
{
  const char* window_title = "webcam-test";
  namedWindow(window_title,CV_WINDOW_AUTOSIZE);
  while(1){
    char c = cvWaitKey(33);
    if(c==27) break;
  }
  destroyWindow(window_title) ;
  return 0;
}
