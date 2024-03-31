//作者：王浩毅
//此文件包含与BGM有关的各种函数
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
}//关闭BGM的函数
void paintmusicplayer() {
	loadimage(&player, "点唱机.png");
}
void musicplayer() {
	getimage(&tempimage, 0, 0, 1200, 675);//记录在点击点唱机前的棋盘状态
	cleardevice();
	putimage(0, 0, &player);//点唱机的贴图
	while (1) {
		getmessage(&msg1);
		if (msg1.x >= 805 && msg1.x <= 1150 && msg1.y >= 230 && msg1.y <= 270 && msg1.message == WM_LBUTTONDOWN) {
			closeBGM();//将现在正在播放的BGM关闭
			mciSendString("open ./春弦.mp3 alias BGM", 0, 0, 0);
			mciSendString("play BGM repeat", 0, 0, 0);
			musicplay = 1;//musicplay=1表示音乐在播放
		}
		if (msg1.x >= 805 && msg1.x <= 1150 && msg1.y >= 285 && msg1.y <= 320 && msg1.message == WM_LBUTTONDOWN) {
			closeBGM();

			mciSendString("open ./遗尘漫步.mp3 alias BGM", 0, 0, 0);
			mciSendString("play BGM repeat", 0, 0, 0);
			musicplay = 1;
		}
		if (msg1.x >= 805 && msg1.x <= 1150 && msg1.y >= 340 && msg1.y <= 380 && msg1.message == WM_LBUTTONDOWN) {
			closeBGM();
			mciSendString("open ./覆潮之下.mp3 alias BGM", 0, 0, 0);
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
			musicplay = 1;//播放按钮
		}
		if (msg1.x >= 940 && msg1.x <= 985 && msg1.y >= 565 && msg1.y <= 585 && msg1.message == WM_LBUTTONDOWN) {
			mciSendString("pause BGM", 0, 0, 0);
			musicplay = 0;//暂停按钮
		}
		if (msg1.x >= 820 && msg1.x <= 880 && msg1.y >= 555 && msg1.y <= 590 && msg1.message == WM_LBUTTONDOWN) {
			putimage(0, 0, &tempimage);//退出按钮，返回上一级界面
			return;
		}

	}


}