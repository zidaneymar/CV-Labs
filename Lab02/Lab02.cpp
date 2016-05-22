#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <random>
#include <algorithm>
using namespace std;
using namespace cv;

uchar average(const Mat& m, int x, int y){
	int result = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			result += m.at<uchar>(i, j);
		}
	}
	result /= 9;
	return static_cast<uchar>(result);
}
uchar median(const Mat& m, int x, int y) {
	vector<uchar> buf;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			buf.push_back(m.at<uchar>(i, j));
		}
	}
	sort(buf.begin(), buf.end());
	return buf[5];
}
const Mat averageRemove(const Mat& m) {
	Mat buf;
	m.copyTo(buf);
	for (int i = 1; i < m.rows - 1; i++) {
		for (int j = 1; j < m.cols - 1; j++) {
			buf.at<uchar>(i, j) = average(m, i, j);
		}
	}
	return buf;
}
const Mat medianRemove(const Mat& m) {
	Mat buf;
	m.copyTo(buf);
	for (int i = 1; i < m.rows - 1; i++) {
		for (int j = 1; j < m.cols - 1; j++) {
			buf.at<uchar>(i, j) = median(m, i, j);
		}
	}
	return buf;
}
const Mat addNoise(const Mat& m){
	Mat buf;
	m.copyTo(buf);
	random_device rd;
	for (int i = 0; i < buf.rows; i++) {
		for (int j = 0; j < buf.cols; j++) {
			double cur = (double)rd() / RAND_MAX;
			if(cur < 3e-2){
				double cur2 = rd() / RAND_MAX;
				if(cur2 < 0.5){
					buf.at<uchar>(i, j) = 0;
				}else{
					buf.at<uchar>(i, j) = 255;
				}
			}
		}
	}
	return buf;
}

int main(int argc, char const *argv[])
{
	Mat img = imread("../lena.bmp", 0);
	Mat buf = addNoise(img);
	imshow("img", buf);
	Mat buf2 = averageRemove(buf);
	imshow("img1", buf2);
	Mat buf3 = medianRemove(buf);
	imshow("img3", buf3);
	waitKey();
	return 0;
}