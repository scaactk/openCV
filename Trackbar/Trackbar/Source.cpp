#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
#define WINDOW_NAME "���Ի��ʾ��" //Ϊ���ڱ��ⶨ��ĺ�

//ȫ�ֱ�����������
const int g_nMaxAlphaValue = 100;//alpha���ֵ
int g_nAlphaValueSlider;//��������Ӧ�ı���
double g_dAlphaValue;
double g_dBetaValue;

//�����洢ͼ��ı���
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

//on_Trackbar()����
//��Ӧ�������Ļص�����

void on_Trackbar(int, void *) {
	//�����ǰAlphacֵ�൱�����ֵ�ı���
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;

	//betaΪ1��ȥalpha
	g_dBetaValue = (1.0 - g_dAlphaValue);
	

	//����alpha��betaֵ������������
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);

	//��ʾЧ��ͼ
	imshow(WINDOW_NAME, g_dstImage);
}

int main(int argc, char** argv){

	//����ͼ����ͼ��ߴ���Ҫ��ͬ��
	g_srcImage1 = imread("a.jpg");
	g_srcImage2 = imread("b.jpg");

	if (!g_srcImage1.data) {
		printf("��ȡ��һ��ͼʧ��\n");
		return -1;
	}
	if (!g_srcImage2.data) {
		printf("��ȡ�ڶ���ͼƬʧ��\n");
		return -1;
	}

	//���û�������ֵΪ100
	g_nAlphaValueSlider = 100;

	//��������
	namedWindow(WINDOW_NAME, 1);

	//�ڴ����д���һ���������ؼ�
	char TrackBarName[50];
	sprintf(TrackBarName, "͸��ֵ %d", g_nAlphaValueSlider);

	createTrackbar(TrackBarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);

	//����ڻص���������ʾ
	on_Trackbar(g_nAlphaValueSlider, 0);
	
	waitKey(0);
	return 0;
}