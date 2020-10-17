#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include"organ.h"
using namespace cv;
using namespace std;
bool capture_IsOpened(VideoCapture cap)
{
	if (!cap.isOpened())
	{
		cout << "無法播放視頻" << endl;
		return -1;
	}
}
bool capture_IsEnd(Mat frame)
{
	if (frame.empty())
	{
		cout << "視頻已播放完" << endl;
		return 0;
	}
}
void organ::image_process()
{
	cvtColor(frame, hsv_image, COLOR_BGR2HSV);
	inRange(hsv_image, Scalar(80,43,46), Scalar(130,255,255), gray_image);
	/*vector<Mat> cannels;
	split(frame, cannels);
	threshold(cannels.at(0) - cannels.at(2), hsv_image, 80, 255, THRESH_BINARY);
	*/
	Mat element = getStructuringElement(MORPH_RECT, Size(7, 7));
	//線性濾波
	blur(gray_image, gray_image, Size(3, 3));
	//閉操作
	morphologyEx(gray_image, temp, MORPH_CLOSE, element);
}
void organ::choose()
{
	vector<vector<cv::Point>> contours;
	vector<Vec4i> hierarchy;
	//提取所有輪廓並建立網狀輪廓結構
	findContours(temp, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
	if (contours.size() != 0)
	{
		for (int i = 0; i < contours.size(); i++)//遍歷所有輪廓
		{
			if (contourArea(contours[i]) < 100)continue;
			//選出父輪廓
			if (hierarchy[i][3] != -1)
			{
				contour_num[hierarchy[i][3]]++; //記錄下每個父輪廓對應的子輪廓數量
			}
		}
		//選出未打擊的扇葉
		for (int j = 0; j < contours.size(); j++)
		{
			if (contour_num[j] == 1) //只有一個內輪廓 
			{
				int ID = hierarchy[j][2]; //記錄該內輪廓的編號
				RotatedRect rect = minAreaRect(contours[ID]);
				float ratio = float(rect.size.height) / float(rect.size.width);
				if (ratio < 2 && ratio>0.5)
				{
					result.push_back(rect);//將識別的結果存儲起來
				}
			}
		}
	}
}
void organ::draw(RotatedRect rect)
{
	//����Ŀ����μ�������
	Point2f P[4];
	rect.points(P);
	for (int i = 0; i < 4; i++)
	{
		line(frame, P[i], P[(i + 1) % 4], Scalar(0, 255, 255), 4, LINE_AA);
	}
	circle(frame, rect.center, 4, Scalar(0, 0, 255), 2);
}
void organ::show()
{
	namedWindow("result");
	imshow("result", temp);
	namedWindow("source");
	imshow("source", frame);
}