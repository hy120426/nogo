//���ߣ�������
//���ļ�������Ϸ�Ľ��������صĺ���
#include<easyx.h>
#include<stdio.h>
#include"ͼ�ν���.h"
#include"huiqi.h"
using namespace std;
ExMessage msg2;
IMAGE win, lose, duihuakuang;
extern bool gamefinish;
extern int shoushu;
void loadfinishimage() {//���ؽ���ʱ����ͼ
	loadimage(&win, "ʤ������.png");
	loadimage(&lose, "ʧ�ܽ���.png");
	loadimage(&duihuakuang, "�Ի���.png", 250, 45);
}
void wingame() {//��һ�ʤ����ͼ
	putimage(0, 0, &win);
	while (1) {
		getmessage(&msg2);
		if (msg2.x >= 35 && msg2.x <= 730 && msg2.y >= 425 && msg2.y <= 470 && msg2.message == WM_LBUTTONDOWN) {
			gameover = 0; return;//gameover=0��ʾ�ؿ�һ��
		}
		if (msg2.x >= 35 && msg2.x <= 730 && msg2.y >= 570 && msg2.y <= 610 && msg2.message == WM_LBUTTONDOWN) {
			gameover = 1; return;//gameover=1��ʾ��Ϸ�������˳���Ϸ
		}
	}
}
void losegame() {//�������������ƣ������ʧ��֮��Ļ��幦��
	putimage(0, 0, &lose);
	putimage(850, 499, &duihuakuang);//�Ƿ����İ�ť��ͼ
	while (1) {
		getmessage(&msg2);
		if (msg2.x >= 35 && msg2.x <= 730 && msg2.y >= 425 && msg2.y <= 470 && msg2.message == WM_LBUTTONDOWN) {
			gamefinish = true; shoushu = 0; gameover = 0; return;
		}
		if (msg2.x >= 35 && msg2.x <= 730 && msg2.y >= 570 && msg2.y <= 610 && msg2.message == WM_LBUTTONDOWN) {
			gamefinish = true; shoushu = 0; gameover = 1; return;
		}
		if (msg2.x >= 850 && msg2.x <= 1100 && msg2.y >= 499 && msg2.y <= 544 && msg2.message == WM_LBUTTONDOWN) {
			//ѡ�˻���
			huiqi();
			return;
		}
	}
}