#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

extern bool capture_IsOpened(VideoCapture cap);//判断是否读取视频成功
extern bool capture_IsEnd(Mat frame);//视频是否结束
class organ
{
public:
	organ() {}
	~organ() {}
	vector<RotatedRect> result;//用来存储识别结果的容器
	void image_process();//图像预处理
	void choose();//筛选出目标扇叶
	void draw(RotatedRect rect);//标定结果
	void show();//窗口显示
	void setframe(VideoCapture cap)//逐帧写入
	{
		cap >> frame;
	}
private:
	Mat frame;//源图像
	Mat hsv_image;//转换颜色空间得到的图像
	Mat gray_image;//二值化得到的图像
	Mat temp;//预处理后得到的图像
	int contour_num[20] = { 0 };//用来存储子轮廓个数的数组	
};


