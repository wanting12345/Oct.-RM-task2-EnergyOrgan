#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include"organ.h"
#include <stdio.h>
#include<time.h>

using namespace cv;
using namespace std;

int main()
{
	//讀取視頻
	VideoCapture cap("/home/yevette/文档/RM-taskfiles/Desktop/buff.avi");
	capture_IsOpened(cap);
	while (1)
	{
		clock_t start,finish;
		double totaltime;
		start=clock();//開始計時
		organ organ;
		organ.setframe(cap);
		//圖像處理
		organ.image_process();
		//篩選出扇葉
		organ.choose();
		//結束計時
		finish=clock();
		totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
		cout<<"deal_time："<<(totaltime * 1000)<<"ms"<<endl;
		//標定結果
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
