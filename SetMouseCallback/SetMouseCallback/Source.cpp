#include<opencv2/opencv.hpp>
using namespace cv;

#define WINDOW_NAME  "���򴰿�,ESC�˳�"

//ȫ�ֺ�������
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void DrawRectangle(cv::Mat& img, cv::Rect box);
void ShowHelpText();

//ȫ�ֱ�������
Rect g_rectangle;
bool g_bDrawingBox = false;//�Ƿ���л���
RNG g_rng(12345);

int main(int argc, char** argv) {
	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;//�߶�600�����800
	srcImage.copyTo(tempImage);
	g_rectangle = Rect(-1, -1, 0, 0);
	srcImage = Scalar::all(255);//��ʼ����ɫ

	//�����������Ļص�����
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);

	//ѭ�������򣬵����л��Ƶı�ʶ��Ϊ��ʱ�����л���
	while (1) {
		srcImage.copyTo(tempImage);//����ԭͼ����ʱ����
		if (g_bDrawingBox) {
			DrawRectangle(tempImage, g_rectangle);//�����Ʊ�־��Ϊ��ʱ���л���
		}
		imshow(WINDOW_NAME, tempImage);
		if (waitKey(10) == 27)break;//����ESC�˳�
	}
	return 0;
}

//���ص����������ݲ�ͬ������¼����в�ͬ�Ĳ���
void on_MouseHandle(int event, int x, int y, int flags, void* param) {
	Mat& image = *(cv::Mat*) param;
	switch (event) {

		//����ƶ���Ϣ
	case EVENT_MOUSEMOVE: {
		if (g_bDrawingBox) {//������Ʊ�ʶ��Ϊ�棬��ѳ��Ϳ��¼��Rect�ͱ�����ȥ
			g_rectangle.width = x - g_rectangle.x;
			g_rectangle.height = y - g_rectangle.y;
		}
	}break;

		//���������Ϣ
	case EVENT_LBUTTONDOWN: {
		g_bDrawingBox = true;
		g_rectangle = Rect(x, y, 0, 0);//��¼��ʼ��
	}break;

		//���̧����Ϣ
	case EVENT_LBUTTONUP: {
		g_bDrawingBox = false;//��ʶ��Ϊfalse

		//�Կ�͸�С����Ĵ���
		if (g_rectangle.width < 0) {
			g_rectangle.x += g_rectangle.width;
			g_rectangle.width *= -1;
		}

		if (g_rectangle.height < 0) {
			g_rectangle.y += g_rectangle.height;
			g_rectangle.height *= -1;
		}

		//���ú������л���
		DrawRectangle(image, g_rectangle);
	}break;

	}
}

//DrawRectangle()����
//�Զ���ľ��λ��ƺ���

void DrawRectangle(cv::Mat& img, cv::Rect box) {
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0,255)));//�����ɫ
}