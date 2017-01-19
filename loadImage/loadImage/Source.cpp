#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

int main() {
	//����ͼ�����ʾ
	Mat girl = imread("a.jpg");
	namedWindow("����ͼƬ");
	imshow("����ͼƬ", girl);

	//ͼ����
	Mat image = imread("test.jpg", 4);
	Mat logo = imread("test2.jpg");

	//��ʾ
	namedWindow("ԭͼ");
	imshow("ԭͼ", image);

	namedWindow("logo");
	imshow("logo", logo);
	
	//����һ��Mat���ͣ����ڴ��ͼ���ROI
	Mat imageROI;

	//����һ
	imageROI = image(Rect(200, 50, logo.cols, logo.rows));

	//������
	//imageROI = image(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));

	//��logo�ӵ�ԭͼ��
	addWeighted(imageROI, 0.1, logo, 0.5, 0., imageROI);

	//��ʾ���
	namedWindow("ԭ��+logoͼ");
	imshow("ԭ��+logo", image);

	//ͼ������
	//��һ��MAtͼ��������ļ�
	imwrite("����ͼ.jpg", image);
	waitKey();
	return 0;
}