#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include"organ.h"
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	//�xȡҕ�l
	VideoCapture cap("D:\\Users\\lenovo\\Desktop\\�������� .avi");
	capture_IsOpened(cap);
	while (1)
	{
		organ organ;
		organ.setframe(cap);
		//ͼ��Ԥ����
		organ.image_process();
		//ɸѡ����Ҷ
		organ.choose();
		//�궨���
		cout << organ.result.size() << endl;
		if (organ.result.size() > 0)
		{
			for (int i = 0; i < organ.result.size(); i++)
			{
				organ.draw(organ.result[i]);
			}
		}
		organ.show();
		waitKey(1);
	}
	return 0;
}
