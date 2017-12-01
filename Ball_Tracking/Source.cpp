#include <iostream> // for standard I/O
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
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
	Mat Image = imread("fifa.jpg");
	imshow("Anzeige", Image);
	waitKey(0);

	Mat midImage;
	cvtColor(Image, midImage, COLOR_BGR2GRAY);
	GaussianBlur(midImage, midImage, Size(9, 9), 2.5, 2.5);
	imshow("Gaussian", midImage);
	waitKey(0);

	vector<Vec3f> circles;
	HoughCircles(midImage, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 100, 0, 0);
	for (size_t i = 0; i<circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(Image, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		circle(Image, center, radius, Scalar(155,50,255), 3, 8, 0);
		cout << cvRound(circles[i][0]) << "\t" << cvRound(circles[i][1]) << "\t"
			<< cvRound(circles[i][2]) << endl;
	}
	imshow("Result", Image);
	waitKey(0);
	/*
	VideoCapture cap(0);

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
		
		// open the WebCam directly
/*		imshow("WebCam", frame);
		if (waitKey(30) >= 0)
			stop = true;

		cvtColor(frame, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7, 7), 5, 5);
		Canny(edges, edges, 0, 30, 3);
		
		// open the WebCam, output << edge after Canny
		imshow("WebCam_edge", edges);
		if (waitKey(30) >= 0)
			stop = true;
		
		vector<Vec3f>circles;
		HoughCircles(edges, circles, CV_HOUGH_GRADIENT, 1.2, 10, 200, 100, 0, 0);

		for (size_t i = 0; i<circles.size(); i++)
		{
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			circle(frame, center, 3, Scalar(255, 255, 255), -1, 8, 0);
			circle(frame, center, radius, Scalar(255, 255, 255), 3, 8, 0);
			cout << cvRound(circles[i][0]) << "\t" << cvRound(circles[i][1]) << "\t"
				<< cvRound(circles[i][2]) << endl;
		}
		
	}*/	

	return 0;
}

