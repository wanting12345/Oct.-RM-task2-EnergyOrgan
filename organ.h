#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

extern bool capture_IsOpened(VideoCapture cap);//�ж��Ƿ��ȡ��Ƶ�ɹ�
extern bool capture_IsEnd(Mat frame);//��Ƶ�Ƿ����
class organ
{
public:
	organ() {}
	~organ() {}
	vector<RotatedRect> result;//�����洢ʶ����������
	void image_process();//ͼ��Ԥ����
	void choose();//ɸѡ��Ŀ����Ҷ
	void draw(RotatedRect rect);//�궨���
	void show();//������ʾ
	void setframe(VideoCapture cap)//��֡д��
	{
		cap >> frame;
	}
private:
	Mat frame;//Դͼ��
	Mat hsv_image;//ת����ɫ�ռ�õ���ͼ��
	Mat gray_image;//��ֵ���õ���ͼ��
	Mat temp;//Ԥ�����õ���ͼ��
	int contour_num[20] = { 0 };//�����洢����������������	
};


