#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "include/chartdir.h"
using namespace std;
using namespace cv;
const Mat linear(const Mat& m, double k, double l) {
	Mat buf;
	m.copyTo(buf);
	for (int i = 0; i < buf.rows; i++) {
		for (int j = 0; j < buf.cols; j++) {
			if (buf.at<uchar>(i, j) * k + l >= 255) {
				buf.at<uchar>(i, j) = 255;
			}
			else {
				buf.at<uchar>(i, j) = buf.at<uchar>(i, j) * k + l;
			}
		}
	}
	return buf;
}
const Mat stretch(const Mat& m, const pair<double, double> &p1, const pair<double, double> &p2) {
	Mat buf;
	m.copyTo(buf);
	double x1 = p1.first;
	double y1 = p1.second;
	double x2 = p2.first;
	double y2 = p2.second;
	for (int i = 0; i < buf.rows; i++) {
		for (int j = 0; j < buf.cols; j++) {
			if (buf.at<uchar>(i, j) < x1) {
				if (buf.at<uchar>(i, j) * y1 / x1 >= 255) {
					buf.at<uchar>(i, j) = 255;
				}
				else {
					buf.at<uchar>(i, j) = buf.at<uchar>(i, j) * y1 / x1;
				}
			}
			else if (buf.at<uchar>(i, j) >= x1 && buf.at<uchar>(i, j) <= x2) {
				double temp = (y2 - y1) / (x2 - x1) * (buf.at<uchar>(i, j) - x1) + y1;
				if (temp >= 255) {
					buf.at<uchar>(i, j) = 255;
				}
				else {
					buf.at<uchar>(i, j) = temp;
				}
			}
			else {
				double temp = (255 - y2) / (255 - x2) * (buf.at<uchar>(i, j) - x2) + y2;
				if (temp >= 255) {
					buf.at<uchar>(i, j) = 255;
				}
				else {
					buf.at<uchar>(i, j) = temp;
				}
			}
		}
	}
	return buf;
}
vector<double> Histogram(const Mat& m, double low, double high){
	vector<double> result(high - low, 0);
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			result[(m.at<uchar>(i, j) - low)]++;
		}
	}
	return result;
}
void opHistogram(Mat &m){
	vector<double> buf1(256, 0);
	vector<double> pro(256, 0);
	vector<double> buf2(256, 0);
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			buf1[m.at<uchar>(i, j)]++;
		}
	}
	for(int i = 0; i <= 255; i++){
		pro[i] = buf1[i] / (m.rows * m.cols);
	}
	
	buf2[0] = pro[0];
	for(int i = 1; i <= 255; i++) {
		buf2[i] = buf2[i - 1] + pro[i];
	}
	
	for(int i = 0; i <= 255; i++){
		buf2[i] = ceil(255 * buf2[i]);
		if(buf2[i] >= 255){
			buf2[i] = 255;
		}
	}
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			m.at<uchar>(i, j) = static_cast<uchar>(buf2[m.at<uchar>(i, j)]);
		}
	}
}
int main(int argc, char** argv) {
	Mat img = imread("../pout.bmp", 0);
	int mode;
	cout << "please select the mode: "  << endl;
	cin >> mode;
	if(mode == 1){
		imshow("img", img);
		double k, m;
		cin >> k >> m;
		Mat linearM = linear(img, k, m);
		imshow("img2", linearM);
	}else if(mode == 2){
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Mat stretchM = stretch(img, make_pair(x1, y1), make_pair(x2, y2));
		imshow("img3", stretchM);
	}else if(mode == 3){
		int low, high;
		cin >> low >> high;
		vector<double> buf = Histogram(img, low, high);
		XYChart *c = new XYChart(500, 500);
		c->setPlotArea(50, 30, 500, 500);
	    c->addBarLayer(DoubleArray(buf.data(), buf.size()));
		c->makeChart("previouse.png");
		imshow("img", img);
		opHistogram(img);
		imshow("img1", img);
		imshow("previouse", imread("previouse.png"));

		vector<double> buf2 = Histogram(img, low, high);
		XYChart *d = new XYChart(500, 500);
		d->setPlotArea(50, 30, 500, 500);
		d->addBarLayer(DoubleArray(buf2.data(), buf2.size()));
		d->makeChart("after.png");
		imshow("after", imread("after.png"));
		delete c;
	}
	waitKey();
	return 0;
}