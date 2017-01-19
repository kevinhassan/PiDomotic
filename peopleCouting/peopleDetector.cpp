#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define SHOW_STEPS            // un-comment or comment this line to show steps or not

// global variables ///////////////////////////////////////////////////////////////////////////////
const cv::Scalar SCALAR_BLACK = cv::Scalar(0.0, 0.0, 0.0);
const cv::Scalar SCALAR_WHITE = cv::Scalar(255.0, 255.0, 255.0);
const cv::Scalar SCALAR_YELLOW = cv::Scalar(0.0, 255.0, 255.0);
const cv::Scalar SCALAR_GREEN = cv::Scalar(0.0, 200.0, 0.0);
const cv::Scalar SCALAR_RED = cv::Scalar(0.0, 0.0, 255.0);

int main (int argc, const char * argv[])
{
  Mat img;
  Mat img2;
  Point crossingLine[2];//Vecteur

  // rajouter
  int peopleInRoomA = 0;
  int peopleInRoomB = 0;

  VideoCapture capture;

  capture.open(0); //Ouvrir la caméra par défault
  capture.set(CV_CAP_PROP_FRAME_WIDTH, 320);
  capture.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

  if (!capture.isOpened()){
    std::cerr<<"Error opening video capture !"<<std::endl;
    return -1;
  }
  capture.read(img);
  capture.read(img2);
/**
* On applique la ligne horizontale à l'image
*/
  int intHorizontalLinePosition = (int)std::round((double)img.rows * 0.35);
  crossingLine[0].x = 0;
  crossingLine[0].y = intHorizontalLinePosition;
  crossingLine[1].x = img.cols - 1;
  crossingLine[1].y = intHorizontalLinePosition;

  char chCheckForEscKey = 0;


  HOGDescriptor hog;
  hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());





  namedWindow("video capture", CV_WINDOW_AUTOSIZE);
  while (capture.isOpened() && chCheckForEscKey != 27)
  {
    capture >> img;
    img2 = img.clone();
    line(img2, crossingLine[0], crossingLine[1], SCALAR_RED, 2);

    vector<Rect> found, found_filtered;

    hog.detectMultiScale(img, found, 0, Size(8,8), Size(32,32), 1.05, 2);

    size_t i, j;
    for (i=0; i<found.size(); i++)
    {
        Rect r = found[i];
        for (j=0; j<found.size(); j++)
            if (j!=i && (r & found[j])==r)
                break;
        if (j==found.size())
            found_filtered.push_back(r);
    }
    for (i=0; i<found_filtered.size(); i++)
    {
	    Rect r = found_filtered[i];
      r.x += cvRound(r.width*0.1);
	    r.width = cvRound(r.width*0.8);
	    r.y += cvRound(r.height*0.06);
	    r.height = cvRound(r.height*0.9);
	    rectangle(img2, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
	   }
      imshow("video capture", img2);
      chCheckForEscKey = waitKey(1);
    }
    return 0;
}
