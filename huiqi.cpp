//作者：张熙
#include<easyx.h>
#include "huiqi.h"
#include "jiegouti.h"
IMAGE fuzhipan;
int copy[11][11];
extern int gameboard[11][11];
extern int shoushu;
int copyshoushu;
extern int inow, jnow;
extern IMAGE bk, white;
extern position board[9][9];
void fuzhi() {
	getimage(&fuzhipan,0, 0, 1200, 675);
	//把画面复制下来
	copyshoushu = shoushu;
	//把手数信息复制下来
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			copy[i][j] = gameboard[i][j];
	//把棋盘复制下来
}
void reset()
{
	copyshoushu=shoushu = 0;
	//清空手数
	jnow = inow = -2;
	//这个与落子提示和行棋算法有关
	getimage(&fuzhipan, 0, 0, 0, 0);
	//清空图像
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			gameboard[i][j]=copy[i][j] = 0;
	//清空棋盘
}
void huiqi() {
	putimage(0, 0, &fuzhipan);
	//把复制的画面贴上去
	shoushu=copyshoushu;
	//把手数跟复制的内容同步了
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			gameboard[i][j] = copy[i][j];
	//把复制的棋盘读进去
}