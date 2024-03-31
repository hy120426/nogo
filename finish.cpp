//此文件包含游戏的结算界面相关的函数
#include<easyx.h>
#include<stdio.h>
#include"图形界面.h"
#include"huiqi.h"
using namespace std;
ExMessage msg2;
IMAGE win, lose, duihuakuang;
extern bool gamefinish;
extern int shoushu;
void loadfinishimage() {//加载结束时的贴图
	loadimage(&win, "胜利界面.png");
	loadimage(&lose, "失败界面.png");
	loadimage(&duihuakuang, "对话框.png", 250, 45);
}
void wingame() {//玩家获胜的贴图
	putimage(0, 0, &win);
	while (1) {
		getmessage(&msg2);
		if (msg2.x >= 35 && msg2.x <= 730 && msg2.y >= 425 && msg2.y <= 470 && msg2.message == WM_LBUTTONDOWN) {
			gameover = 0; return;//gameover=0表示重开一局
		}
		if (msg2.x >= 35 && msg2.x <= 730 && msg2.y >= 570 && msg2.y <= 610 && msg2.message == WM_LBUTTONDOWN) {
			gameover = 1; return;//gameover=1表示游戏结束，退出游戏
		}
	}
}
void losegame() {//与上述函数类似，添加了失败之后的悔棋功能
	putimage(0, 0, &lose);
	putimage(850, 499, &duihuakuang);//是否悔棋的按钮贴图
	while (1) {
		getmessage(&msg2);
		if (msg2.x >= 35 && msg2.x <= 730 && msg2.y >= 425 && msg2.y <= 470 && msg2.message == WM_LBUTTONDOWN) {
			gamefinish = true; shoushu = 0; gameover = 0; return;
		}
		if (msg2.x >= 35 && msg2.x <= 730 && msg2.y >= 570 && msg2.y <= 610 && msg2.message == WM_LBUTTONDOWN) {
			gamefinish = true; shoushu = 0; gameover = 1; return;
		}
		if (msg2.x >= 850 && msg2.x <= 1100 && msg2.y >= 499 && msg2.y <= 544 && msg2.message == WM_LBUTTONDOWN) {
			//选了悔棋
			huiqi();
			return;
		}
	}
}
