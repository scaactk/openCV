#include<opencv2\highgui\highgui.hpp>//opencv highguiģ��ͷ�ļ�
#include<opencv2\imgproc\imgproc.hpp>//ͼ����ͷ�ļ�
using namespace cv;

int main()
{
	//����ԭͼ
	Mat srcImage = imread("a.jpg");

	//��ʾԭͼ
	imshow("ԭͼ", srcImage);

	//��ʴ����
	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat dstImage;
	erode(srcImage, dstImage, element);

	//��ʾЧ��
	imshow("Ч��ͼ����ʴ����", dstImage);
	waitKey(0);
}
