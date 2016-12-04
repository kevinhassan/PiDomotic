#include <ctime>
#include <iostream>
#include <raspicam/raspicam_cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>
using namespace cv; 
 
int main ( int argc,char **argv ) {
	namedWindow("Raspicam", WINDOW_AUTOSIZE);
	std::cout<<"Press any key to close the window"<<std::endl;
	waitKey(0);
	return 0;
}
