#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <cmath>
using namespace std;
using namespace cv;

uchar sobelHorizontal(const Mat& m, int x, int y) {
	int result = 0;
	result = -(m.at<uchar>(x - 1, y - 1) + 2 * m.at<uchar>(x, y - 1) + m.at<uchar>(x + 1, y - 1));
	result += (m.at<uchar>(x - 1, y + 1) + 2 * m.at<uchar>(x, y + 1) + m.at<uchar>(x + 1, y + 1));
	if(result > 255){
		result = 255;
	}
	if(result < -255){
		result = -255;
	}
	result = abs(result);
	return static_cast<uchar>(result);
}
uchar sobelVertival(const Mat& m, int x, int y) {
	int result = 0;
	result = -(m.at<uchar>(x - 1, y - 1) + 2 * m.at<uchar>(x - 1, y) + m.at<uchar>(x - 1, y + 1));
	result += (m.at<uchar>(x + 1, y - 1) + 2 * m.at<uchar>(x + 1, y) + m.at<uchar>(x + 1, y + 1));
	if(result > 255){
		result = 255;
	}
	if(result < -255){
		result = -255;
	}
	result = abs(result);
	return static_cast<uchar>(result);
}
const Mat sobel(const Mat& m) {
	Mat buf;
	m.copyTo(buf);
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			int cur = sobelVertival(m, i, j) + sobelHorizontal(m, i, j);
			if(cur > 255){
				buf.at<uchar>(i, j) = static_cast<uchar>(255);
			}else{
				buf.at<uchar>(i, j) = static_cast<uchar>(0);
			}
		}
	}
	return buf;
}

uchar laplaceHelp1(const Mat& m, int x, int y) {
	int result = 0;
	result += (m.at<uchar>(x, y - 1) + m.at<uchar>(x, y + 1) + m.at<uchar>(x + 1, y) + m.at<uchar>(x - 1, y) - 4 * m.at<uchar>(x, y));
	if(result > 255){
		result = 255;
	}
	if(result < -255){
		result = -255;
	}
	result = abs(result);
	return static_cast<uchar>(result);
}

uchar laplaceHelp2(const Mat& m, int x, int y) {
	int result = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			result -= m.at<uchar>(i, j);
		}
	}
	result += 9 * m.at<uchar>(x, y);
	if(result > 255){
		result = 255;
	}
	if(result < -255){
		result = -255;
	}
	result = abs(result);
	return static_cast<uchar>(result);
}


const Mat laplace(const Mat& m) {
	Mat buf;
	m.copyTo(buf);
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			int cur = laplaceHelp2(m, i, j) + laplaceHelp1(m, i, j);
			if(cur > 255){
				buf.at<uchar>(i, j) = static_cast<uchar>(255);
			}else{
				buf.at<uchar>(i, j) = static_cast<uchar>(0);
			}
		}
	}
	return buf;
}
int main(int argc, char const *argv[])
{
	Mat img = imread("../lena.bmp", 0);
	Mat buf = sobel(img);
	imshow("img", buf);
	Mat buf2 = laplace(img);
	imshow("img2", buf2);
	waitKey();
	return 0;
}