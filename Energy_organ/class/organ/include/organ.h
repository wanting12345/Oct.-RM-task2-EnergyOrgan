#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//判斷是否讀取視頻成功
extern bool capture_IsOpened(VideoCapture cap);
//視頻是否結束
extern bool capture_IsEnd(Mat frame);

class organ
{
public:
	organ() {}
	~organ() {}
	vector<RotatedRect> result;//存儲識別結果的容器
	void image_process();//圖像預處理
	void choose();//篩選出目標扇葉
	void draw(RotatedRect rect);//標定結果
	void show();//窗口顯示
	void setframe(VideoCapture cap)//逐幀寫入
	{
		cap >> frame;
	}
private:
	Mat frame;//源圖像
	Mat hsv_image;//轉換顏色空間得到的圖像
	Mat gray_image;//二值化得到的圖像
	Mat temp;//預處理得到的圖像
	int contour_num[20] = { 0 };//用來存儲子輪廓個數的數組
};


