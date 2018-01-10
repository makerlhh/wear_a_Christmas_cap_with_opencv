#include<opencv2/objdetect/objdetect.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp> 
#include <opencv2/core/core.hpp>
#include<vector>
#include<iostream>>

using namespace cv;

//人脸检测的类  
CascadeClassifier faceCascade;

int main()
{
	Mat imgin = imread("222.png");
	faceCascade.load("C:/Program Files/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml");   //加载分类器
	Mat img;
	Mat imgGray;
	std::vector<Rect> faces;
	resize(imgin, img, Size(500, 700), 0, 0, CV_INTER_LINEAR);
	if (img.empty())
	{
		return 1;
	}

	if (img.channels() == 3)
	{
		cvtColor(img, imgGray, CV_RGB2GRAY);
	}
	else
	{
		imgGray = img;
	}

	faceCascade.detectMultiScale(imgGray, faces, 1.2, 6, 0, Size(0, 0));   //检测人脸  
	int i;
	if (faces.size()>0)
	{
		for (i = 0; i<faces.size(); i++)
		{
			rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),Scalar(0, 255, 255), 5, 8);    //框出人脸位置  
		}
	}
	Mat hat;
	Mat hat1;
	Mat logo = imread("12.jpg");
	Mat logo1 = imread("12.jpg",0);//过滤黑色
	Mat imageROI;//定义感兴趣ROI区域
	resize(logo, hat, Size(faces[i].width, faces[i].height), 0, 0, CV_INTER_LINEAR);//调整帽子大小
	resize(logo1, hat1, Size(faces[i].width, faces[i].height), 0, 0, CV_INTER_LINEAR);
	imageROI = img(cv::Rect((faces[i].x)*1, (faces[i].y) - (faces[i].height)*0.9, hat.rows, hat.rows));//把ROI区域设置在脸方框上方
	hat.copyTo(imageROI, hat1);//把帽子贴在ROI区域
	namedWindow("11", 0);
	cvResizeWindow("11", 500, 700);
	imshow("11", img);
	waitKey(0);
	return 0;
}