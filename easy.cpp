//作者：王浩毅
//此文件包含简单模式的相关算法
#include"tizino.h"
#include "jiegouti.h"
#include"easy.h"
#include<easyx.h>
#include<random>
#include<iostream>
using namespace std;
int oki[81] = {}, okj[81] = {};
int oknum = 0;
extern int inow, jnow;
extern int gameboard[11][11];
extern position board[9][9];
extern IMAGE bk;
extern IMAGE white;
extern IMAGE tip;
extern random_device rd;//用于生成随机数种子

void xiaqi_easy() {
	memset(oki, 0, sizeof(oki));//表示可下棋的i位置
	memset(okj, 0, sizeof(okj));//表示可下棋的j位置
	oknum = 0;//表示可下棋的位置个数
	bool finish = true;//指示游戏是否结束的变量
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {//遍历，尝试ij位置能否落白子
			if (gameboard[i][j] == 0) {
				gameboard[i][j] = 2;
				if (tizi_no(i, j, 2)) {
					finish = false;
					oki[oknum] = i;
					okj[oknum] = j;//每个oknum可以对应一个ij值
					oknum++;
				}gameboard[i][j] = 0;
			}
		}
	}
	if (finish) {//如果finish值为true则游戏结束
		jnow = -1; return;
	}
	else {
		mt19937 randomok(rd());//随机数生成器
		uniform_int_distribution<int> dis(0, oknum - 1);//在可以下的位置随机生成一个位置
		int x = dis(randomok);
		inow = oki[x];
		jnow = okj[x];
		gameboard[inow][jnow] = 2;
		putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &bk, SRCPAINT);
		putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &tip, SRCAND);//下棋的贴图
	}
}
