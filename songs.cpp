//���ߣ�������
//���ļ�������BGM�йصĸ��ֺ���
#include<easyx.h>
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include"start.h"
using namespace std;
extern int musicplay;
IMAGE player;
IMAGE tempimage;
ExMessage msg1;
void closeBGM() {
	mciSendString("close BGM", 0, 0, 0);
}//�ر�BGM�ĺ���
void paintmusicplayer() {
	loadimage(&player, "�㳪��.png");
}
void musicplayer() {
	getimage(&tempimage, 0, 0, 1200, 675);//��¼�ڵ���㳪��ǰ������״̬
	cleardevice();
	putimage(0, 0, &player);//�㳪������ͼ
	while (1) {
		getmessage(&msg1);
		if (msg1.x >= 805 && msg1.x <= 1150 && msg1.y >= 230 && msg1.y <= 270 && msg1.message == WM_LBUTTONDOWN) {
			closeBGM();//���������ڲ��ŵ�BGM�ر�
			mciSendString("open ./����.mp3 alias BGM", 0, 0, 0);
			mciSendString("play BGM repeat", 0, 0, 0);
			musicplay = 1;//musicplay=1��ʾ�����ڲ���
		}
		if (msg1.x >= 805 && msg1.x <= 1150 && msg1.y >= 285 && msg1.y <= 320 && msg1.message == WM_LBUTTONDOWN) {
			closeBGM();

			mciSendString("open ./�ų�����.mp3 alias BGM", 0, 0, 0);
			mciSendString("play BGM repeat", 0, 0, 0);
			musicplay = 1;
		}
		if (msg1.x >= 805 && msg1.x <= 1150 && msg1.y >= 340 && msg1.y <= 380 && msg1.message == WM_LBUTTONDOWN) {
			closeBGM();
			mciSendString("open ./����֮��.mp3 alias BGM", 0, 0, 0);
			mciSendString("play BGM repeat", 0, 0, 0);
			musicplay = 1;
		}
		if (msg1.x >= 805 && msg1.x <= 1150 && msg1.y >= 395 && msg1.y <= 430 && msg1.message == WM_LBUTTONDOWN) {
			closeBGM();
			mciSendString("open ./Everything's_Alright.mp3 alias BGM", 0, 0, 0);
			mciSendString("play BGM repeat", 0, 0, 0);
			musicplay = 1;
		}
		if (msg1.x >= 805 && msg1.x <= 1150 && msg1.y >= 450 && msg1.y <= 485 && msg1.message == WM_LBUTTONDOWN) {
			closeBGM();
			mciSendString("open ./Speed_of_Light.mp3 alias BGM", 0, 0, 0);
			mciSendString("play BGM repeat", 0, 0, 0);
			musicplay = 1;
		}
		if (msg1.x >= 805 && msg1.x <= 1150 && msg1.y >= 505 && msg1.y <= 545 && msg1.message == WM_LBUTTONDOWN) {
			closeBGM();
			mciSendString("open ./damedane.mp3 alias BGM", 0, 0, 0);
			mciSendString("play BGM repeat", 0, 0, 0);
			musicplay = 1;
		}
		if (msg1.x >= 1060 && msg1.x <= 1110 && msg1.y >= 560 && msg1.y <= 575 && msg1.message == WM_LBUTTONDOWN) {
			mciSendString("play BGM repeat", 0, 0, 0);
			musicplay = 1;//���Ű�ť
		}
		if (msg1.x >= 940 && msg1.x <= 985 && msg1.y >= 565 && msg1.y <= 585 && msg1.message == WM_LBUTTONDOWN) {
			mciSendString("pause BGM", 0, 0, 0);
			musicplay = 0;//��ͣ��ť
		}
		if (msg1.x >= 820 && msg1.x <= 880 && msg1.y >= 555 && msg1.y <= 590 && msg1.message == WM_LBUTTONDOWN) {
			putimage(0, 0, &tempimage);//�˳���ť��������һ������
			return;
		}

	}


}