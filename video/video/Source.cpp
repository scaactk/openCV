#include <opencv2\opencv.hpp>
using namespace cv;

int main() {
	//������Ƶ
	VideoCapture capture;
	capture.open(0);//��ȡ����ͷ
	//capture.open("test.mp4");//��ȡ��Ƶ

	//ѭ����ʾÿһ֡
	while (1) {
		Mat frame;//����һ��Mat���������ڴ洢ÿһ֡ͼ��
		capture >> frame;//��ȡ��ǰ֡
		imshow("��ȡ��Ƶ", frame);//��ʾ
		waitKey(30);//��ʱ30ms
	}
	return 0;
}