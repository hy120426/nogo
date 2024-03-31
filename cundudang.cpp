//作者：张熙
#include<easyx.h>
#include "huiqi.h"
#include<fstream>
#include<easyx.h>
using namespace std;
extern int gameboard[11][11];
extern int shoushu;
IMAGE cundangzhiqian,baocun;
void cundang() {
	ofstream cunqipan("dangan.txt",ios::out);
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			cunqipan << gameboard[i][j];
	cunqipan.close();
	//通过一个文档储存棋盘上的每一个点的状态
	getimage(&cundangzhiqian,0,0,1200,675); 
	//把存档之前的画面先保存下来
	putimage(426, 200, &baocun);
	//在屏幕上显示“保存成功”的字样
	Sleep(600);
	//让这个字样存在0.6秒
	putimage(0, 0, &cundangzhiqian);
	//把之前保存好的画面再放上去，结束
}
void dudang() {
	ifstream duqipan("dangan.txt", ios::in);
	char yubei;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++) {
			duqipan >> yubei;
			gameboard[i][j]=yubei-'0';
			if (gameboard[i][j]) shoushu++;
		}
	duqipan.close();
	//将文档内容读出来，shoushu手数是跟行棋算法有关的一个量
	//读档之后当然也要同步手数
	shoushu /= 2;
}