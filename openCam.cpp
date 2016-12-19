#include <math.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/videoio/videoio.hpp"
#include <vector>

#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

/* Global variables*/
const char* window_title = "capture-camera";
const char* face_cascade_name = "haarcascade_frontalface_alt.xml";


int main( int argc, char** argv)
{
  VideoCapture capture;
  Mat frame;
  CascadeClassifier face_cascade;
  capture.open(0); //open default camera

  if( !face_cascade.load( face_cascade_name ) )
  {
    printf("Error loading face cascade\n");
    return -1;
  };
  //If camera doesn't work we print and return an error
  if (!capture.isOpened()){
    printf("Error opening video capture ! \n");
    return -1;
  }

  namedWindow(window_title,CV_WINDOW_AUTOSIZE);
  while(capture.read(frame)){
    if( frame.empty() )
    {
      printf("No captured frame -- Break!");
      break;
    }
    vector<Rect> faces;
    Mat frame_gray;

    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
    printf("%zd face(s) are found.\n", faces.size());

    imshow(window_title, frame);
    if(waitKey(30) >= 0) break; //press any key to exit
  }
  destroyWindow(window_title) ;
  return 0;
}
