//本文件包含处理落子提示的函数
#include<easyx.h>
#include"tip.h"
#include "jiegouti.h"
extern int inow, jnow, copyi, copyj;
extern IMAGE bk, white;
extern position board[9][9];
void returnwhite() {//由于电脑下棋时的贴图为红色，用这个函数将红色棋子覆盖为白色
	if (inow != -2) {//inow=-2为初始状态，也就是第一步，第一步没有“前一步”
		putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &bk, SRCPAINT);
		putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &white, SRCAND);
		//inow，jnow记录了电脑最新一次落子的位置
	}
}
void huiqireturn() {//用于处理悔棋时落子提示的问题
	if (inow == -2)return;
	putimage(board[copyi - 1][copyj - 1].x - 22, board[copyi - 1][copyj - 1].y - 30, &bk, SRCPAINT);
	putimage(board[copyi - 1][copyj - 1].x - 22, board[copyi - 1][copyj - 1].y - 30, &white, SRCAND);
	inow = copyi; jnow = copyj;//copyi，copyj用于记录电脑倒数第二次落子的位置
}
