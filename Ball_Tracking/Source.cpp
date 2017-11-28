#include <iostream> // for standard I/O
#include <opencv2/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
//#include <string>   // for strings
//#include <iomanip>  // for controlling float print precision
//#include <sstream>  // string to number conversion
//#include <opencv2/core.hpp>     // Basic OpenCV structures (cv::Mat, Scalar)
//#include <opencv2/imgproc/imgproc.hpp>  
//#include <opencv2/core/core.hpp>  

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);

	// open the WebCam of Laptop
	/*
	while (1)
	{
	Mat frame;
	cap >> frame;
	imshow("WebCam", frame);
	waitKey(30);
	}
	*/

	// open the WebCam, output << edge after Canny
	if (!cap.isOpened())
	{
		return -1;
	}
	Mat frame;
	Mat edges;

	bool stop = false;
	while (!stop)
	{
		cap >> frame;
		cvtColor(frame, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("WebCam", edges);
		if (waitKey(30) >= 0)
			stop = true;
	}

	return 0;
}

