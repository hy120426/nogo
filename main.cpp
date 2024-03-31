#include<random>
#include <iostream>
#include<easyx.h>
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>
#include<cmath>
#pragma comment(lib,"winmm.lib")
#include "huiqi.h"
#include "tizino.h"
#include "gameboard.h"
#include "culculateqi.h"
#include "jiegouti.h"
#include"ichi.h"
#include"start.h"
#include "easy.h"
#include "cundudang.h"
#include"songs.h"
#include"finish.h"
#include"normal.h"
#include"tip.h"
using namespace std;
extern bool gameover=false;
extern int shoushu;
 bool gamefinish = false;
const int deep = 3;
int flag;
int musicplay = 1;
int copyi, copyj;
int gameboard[11][11] = {};//判断某一点是否有棋子，电脑用2，人类用1
int positionx = -1, positiony = -1; //用来判断人类是否输掉比赛在main函数里也要用，所以改成全局变量了
 int inow, jnow; //用来判断电脑是否输也要用。。。实际上用kkt[0].i也一样的，完全多余但我不想删了，如果要补落子提示这个还是用的上
//extern IMAGE fuzhipan;
qi kkt[2]; position board[9][9];
IMAGE start;
IMAGE board0, black, white, bk,tip,pauseBGM,startBGM;
ExMessage msg;

int delta[9] = { 46,47,49,51,53,55,57,60,62 };//计算格点坐标时用，可不管

int main() {
	loadbks(); //load背景
	gedian();  //储存点的坐标
	initgraph(1200, 675); //开界面
	loadfinishimage();  //load结算画面
	loadimage(&board0, "棋盘.png");
	loadimage(&black, "黑棋.png");
	loadimage(&white, "白棋.png");
	loadimage(&bk, "棋子.png");
	loadimage(&tip, "提示.png");
	loadimage(&pauseBGM, "暂停音乐.png");
	loadimage(&startBGM, "播放音乐.png");
	settextstyle(100, 0, "宋体");
	mciSendString("open ./遗尘漫步.mp3 alias BGM", 0, 0, 0); 
	//load各种图，播bgm
	while (!gameover) { //进入游戏
		reset(); //对棋盘和悔棋相关功能进行reset
		gamefinish = false;
		randombk(); //开始paint主菜单
		paintbutton();
		BGM();
		gameover = startgame();
		if (gameover)return 0;
		/*putimage(0, 0, &board0);*/
		//getimage(&fuzhipan, 0, 0, 1200, 675);
		while (!gamefinish) {

			while (1) {
				getmessage(&msg);
				if (msg.x >= 990 && msg.x <= 1200 && msg.y >= 270 && msg.y <= 335 && msg.message == WM_LBUTTONDOWN) {
					huiqi();
					huiqireturn();
					//悔棋的代码
				}
				if (msg.x >= 960 && msg.x <= 1200 && msg.y >= 477 && msg.y <= 535 && msg.message == WM_LBUTTONDOWN) {
					cundang();//存档的代码
				}
				if (msg.x >= 990 && msg.x <= 1200 && msg.y >= 375 && msg.y <= 425 && msg.message == WM_LBUTTONDOWN) {
					paintmusicplayer();
					musicplayer();
					//点唱机代码
				}
				if (msg.x >= 980 && msg.x <= 1200 && msg.y >= 566 && msg.y <= 625 && msg.message == WM_LBUTTONDOWN) {
					gamefinish = true; shoushu = 0; break;
				}

				if (msg.lbutton) {
					if (luozi(msg.x, msg.y)) {
						copyi = inow;
						copyj = jnow;
						break;
					}
				}  //落子成功才break	

			}
			if (gamefinish) break;

			if (!tizi_no(positiony + 1, positionx + 1, 1)) losegame();
			else {
				returnwhite();
				switch (flag) {
				case 0:
					xiaqi_easy();
					if (jnow == -1) {
						gamefinish = true;
						shoushu = 0;
						wingame();
					}
					break;//easy
				case 1:
					xiaqi_normal();
					if (jnow == -1) {
						gamefinish = true;
						shoushu = 0;
						wingame();
					}
					break;//normal
				case 2:
					xiaqi_difficult();//difficult
					if (jnow == -1) {
						shoushu = 0;
						gamefinish = true;
						wingame();
					}
					break;
				}
			}	
		}
	}
	return 0;
}