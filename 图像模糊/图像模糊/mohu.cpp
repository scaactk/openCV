#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main() {
	//����ԭʼͼ
	Mat srcImage = imread("a.jpg");

	//��ʾ
	imshow("��ֵ�˲���ԭͼ", srcImage);

	//���о�ֵ�˲�����
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));

	//��ʾ
	imshow("��ֵ�˲���Ч��", dstImage);
	waitKey(0);
}