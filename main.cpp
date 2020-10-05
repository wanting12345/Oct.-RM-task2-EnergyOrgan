#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include"organ.h"
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	//讀取視頻
	VideoCapture cap("D:\\Users\\lenovo\\Desktop\\能量机关 .avi");
	capture_IsOpened(cap);
	while (1)
	{
		organ organ;
		organ.setframe(cap);
		//图像预处理
		organ.image_process();
		//筛选出扇叶
		organ.choose();
		//标定结果
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
