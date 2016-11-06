#include <stdio.h>
#include <stdlib.h>
#include <opencv/highgui.h>

int main (int argc, char* argv[])
{
  const char* window_title = "Test Camera ";
  cvNamedWindow (window_title, CV_WINDOW_AUTOSIZE);
  IplImage* frame;
  CvCapture* capture;
  if( argc == 1){
    capture = cvCreateCameraCapture(0);
  }else{
    capture = cvCreateFileCapture( argv[1] );
  }
  assert( capture != NULL);
  while(1){
    frame = cvQueryFrame( capture );
    if( !frame ) break;
    cvShowImage( window_title, frame );
    char c = cvWaitKey(33);
    if( c == 27 ) break;
  }
  cvReleaseCapture( &capture );
  cvDestroyWindow( window_title );

  return EXIT_SUCCESS;
}
