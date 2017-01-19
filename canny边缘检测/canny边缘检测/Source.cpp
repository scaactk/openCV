#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main() {
	Mat srcImage;
	srcImage = imread("a.jpg");
	imshow("ԭʼͼ:canny��Ե���",srcImage);

	Mat edge, grayImage;

	//��ԭͼת��Ϊ�Ҷ�ͼ��
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);

	//����3x3�ں�������
	blur(grayImage, edge, Size(3, 3));

	//����Canny����
	Canny(edge, edge, 3, 9, 3);

	//��ʾЧ��
	imshow("Ч����Canny��Ե���", edge);

	waitKey(0);
}