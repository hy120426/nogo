//作者：王浩毅
//此文件包含与开始界面相关的函数
#include<random>
#include <iostream>
#include<easyx.h>
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "cundudang.h"
#include"start.h"
#include "jiegouti.h"
#include "huiqi.h"

using namespace std;

struct button {
	IMAGE image0;
	char* str;
}buttonnandu;//用于封装调整难度的按钮
IMAGE starts[10], logo, logobk, button1, button2, button3, button4;
IMAGE* p = starts;
extern position board[9][9];
extern int flag;//用于判断选择的难度
extern int gameboard[11][11];
extern IMAGE board0, bk, black, white, baocun, pauseBGM, startBGM;
extern int musicplay;
random_device rd;//用于生成随机数种子
mt19937 randomx(rd());//随机数生成器
uniform_int_distribution<int> dis(0, 9);//随机数分布器 闭区间

void BGM()//播放音乐
{
	//打开音乐，播放音乐  alias取别名 repeat重复播放
	if (musicplay) {//musicplay表示音乐的播放状态，1表示播放，0表示未播放
		mciSendString("play BGM repeat", 0, 0, 0);
		putimage(0, 615, &pauseBGM);///播放时，贴图“暂停音乐”
	}
	else {
		mciSendString("pause BGM", 0, 0, 0);
		putimage(0, 615, &startBGM);//暂停时，贴图“播放音乐”
	}
}
void loadbks() {
	loadimage(p, "界面1.png");
	p++;
	loadimage(p, "界面2.png");
	p++;
	loadimage(p, "界面3.png");
	p++;
	loadimage(p, "界面4.png");
	p++;
	loadimage(p, "界面5.png");
	p++;
	loadimage(p, "界面6.png");
	p++;
	loadimage(p, "界面7.png");
	p++;
	loadimage(p, "界面8.png");
	p++;
	loadimage(p, "界面9.png");
	p++;
	loadimage(p, "界面10.png");
	loadimage(&button1, "按钮-读档.png");
	loadimage(&button2, "按钮-难度.png");
	loadimage(&button3, "按钮-开始.png");
	loadimage(&button4, "按钮-退出.png");
	loadimage(&logo, "logo.png");
	loadimage(&logobk, "logobk.png");
	loadimage(&baocun, "保存.png", 400, 172);
}
void randombk() {
	//加载随机背景，具体做法为：
	//将图片储存在一个IMAGE数组中，然后利用随机数生成来随机图片
	int x0 = dis(randomx);
	putimage(0, 0, &starts[x0]);
	putimage(0, 0, &logobk, SRCPAINT);
	putimage(0, 0, &logo, SRCAND);
}
void paintbutton() {
	putimage(930, 170, &button1);
	putimage(930, 430, &button3);
	putimage(930, 560, &button4);
}
int startgame() {
	//难度调整
	char str1[] = "简 单";
	char str2[] = "普 通";
	char str3[] = "困 难";
	settextcolor(RGB(104, 127, 134));
	settextstyle(45, 20, "宋体");
	setbkmode(TRANSPARENT);
	buttonnandu.image0 = button2;
	putimage(930, 300, &button2);
	//用flag判断难度选择，flag为0,1,2分别对应简单普通困难
	if (flag == 0) { buttonnandu.str = str1; }
	else if (flag == 1) { buttonnandu.str = str2; }
	else { buttonnandu.str = str3; }
	outtextxy(1055, 310, buttonnandu.str);//贴图（简单普通困难）
	ExMessage msg0; while (1) {
		while (peekmessage(&msg0)) {
			if (msg0.x >= 930 && msg0.x <= 1200 && msg0.y >= 170 && msg0.y <= 250 && msg0.message == WM_LBUTTONDOWN)
			{//读档按钮，点击后调用读档函数
				dudang();
				putimage(0, 0, &board0);
				for (int i = 1; i <= 9; i++)
					for (int j = 1; j <= 9; j++) {
						if (gameboard[i][j] == 1) {
							putimage(board[i - 1][j - 1].x - 22, board[i - 1][j - 1].y - 30, &bk, SRCPAINT);
							putimage(board[i - 1][j - 1].x - 22, board[i - 1][j - 1].y - 30, &black, SRCAND);
						}
						if (gameboard[i][j] == 2) {
							putimage(board[i - 1][j - 1].x - 22, board[i - 1][j - 1].y - 30, &bk, SRCPAINT);							//if(steps%2)//判断该下黑棋还是白棋
							putimage(board[i - 1][j - 1].x - 22, board[i - 1][j - 1].y - 30, &white, SRCAND);
						}
					}//通过贴图将存档中的棋盘状态展现出来
				fuzhi();//复制当前棋盘，用于悔棋
				return 0;
			}

			if (msg0.x >= 930 && msg0.x <= 1200 && msg0.y >= 300 && msg0.y <= 380 && msg0.message == WM_LBUTTONDOWN)
			{//点击难度选择按钮，flag的值会随之改变，从而实现难度选择
				++flag %= 3;
				if (flag == 0) { buttonnandu.str = str1; }
				else if (flag == 1) { buttonnandu.str = str2; }
				else { buttonnandu.str = str3; }
				putimage(930, 300, &button2);
				outtextxy(1055, 310, buttonnandu.str);
			}
			if (msg0.x >= 930 && msg0.x <= 1200 && msg0.y >= 430 && msg0.y <= 510 && msg0.message == WM_LBUTTONDOWN)
			{//点击开始按钮，开始游戏，此时取决于flag的值会选择不同难度的算法
				cleardevice();
				putimage(0, 0, &board0);
				return 0;
			}
			if (msg0.x >= 0 && msg0.x <= 220 && msg0.y >= 615 && msg0.y <= 675 && msg0.message == WM_LBUTTONDOWN)
			{//点击暂停/播放音乐的按钮，musicplay的值会随之改变，通过调用BGM函数实现音乐的暂停与播放
				++musicplay %= 2;
				BGM();

			}
			if (msg0.x >= 930 && msg0.x <= 1200 && msg0.y >= 560 && msg0.y <= 640 && msg0.message == WM_LBUTTONDOWN) {
				//点击退出按钮，结束游戏
				closegraph(); return 1;
			}

		}

	}
}


