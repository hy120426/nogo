//���ߣ�������
//���ļ��������̵ľ�����Ϣ
#include "ichi.h"
#include"jiegouti.h"
#include<cmath>
#include<easyx.h>
#include "huiqi.h"

extern position board[9][9];
extern int delta[9];
extern int gameboard[11][11];
extern IMAGE bk;
extern IMAGE black;
extern int positionx;
extern int positiony;
extern int inow;

void gedian()
{//�������̲�������ͼ�����λ�ò������������������¼ÿ������������ϵ�λ��
	board[0][0].x = 446;
	board[0][0].y = 95;
	for (int i = 0; i < 9; i++) {
		board[0][i].x = board[0][0].x + delta[0] * i;
		board[0][i].y = board[0][0].y;
	}
	board[1][0].x = 438;
	board[1][0].y = 132;
	for (int i = 0; i < 9; i++) {
		board[1][i].x = board[1][0].x + delta[1] * i;
		board[1][i].y = board[1][0].y;
	}
	board[2][0].x = 430;
	board[2][0].y = 171;
	for (int i = 0; i < 9; i++) {
		board[2][i].x = board[2][0].x + delta[2] * i;
		board[2][i].y = board[2][0].y;
	}
	board[3][0].x = 420;
	board[3][0].y = 213;
	for (int i = 0; i < 9; i++) {
		board[3][i].x = board[3][0].x + delta[3] * i;
		board[3][i].y = board[3][0].y;
	}
	board[4][0].x = 411;
	board[4][0].y = 255;
	for (int i = 0; i < 9; i++) {
		board[4][i].x = board[4][0].x + delta[4] * i;
		board[4][i].y = board[4][0].y;
	}
	board[5][0].x = 402;
	board[5][0].y = 300;
	for (int i = 0; i < 9; i++) {
		board[5][i].x = board[5][0].x + delta[5] * i;
		board[5][i].y = board[5][0].y;
	}
	board[6][0].x = 393;
	board[6][0].y = 343;
	for (int i = 0; i < 9; i++) {
		board[6][i].x = board[6][0].x + delta[6] * i;
		board[6][i].y = board[6][0].y;
	}
	board[7][0].x = 382;
	board[7][0].y = 396;
	for (int i = 0; i < 9; i++) {
		board[7][i].x = board[7][0].x + delta[7] * i;
		board[7][i].y = board[7][0].y;
	}
	board[8][0].x = 371;
	board[8][0].y = 445;
	for (int i = 0; i < 9; i++) {
		board[8][i].x = board[8][0].x + delta[8] * i;
		board[8][i].y = board[8][0].y;
	}
}

bool luozi(int x, int y)
{//��������������������ʱ����ͼ����
	positionx = -1; positiony = -1;
	for (int i = 0; i < 9; i++) { if (abs(y - board[i][0].y) < 17) { positiony = i; break; } }
	if (positiony < 0)return 0;//�ж��Ƿ������������⣬�������������������ʧ�ܣ�����0
	for (int i = 0; i < 9; i++) { if (2 * abs(x - board[positiony][i].x) < delta[positiony]) { positionx = i; break; } }
	if (positionx < 0)return 0;
	if (gameboard[positiony + 1][positionx + 1])return 0;//����˵�������������ʧ�ܣ�����0
	if (inow == -2) {
		if (positionx + 1 == 5 && positiony + 1 == 5)return 0;//�����һ�������м䣬������ʧ�ܣ�����0
	}
	fuzhi();//���Ƶ�ǰ����״̬������ʱҪ��
	gameboard[positiony + 1][positionx + 1] = 1;

	putimage(board[positiony][positionx].x - 22, board[positiony][positionx].y - 30, &bk, SRCPAINT);
	putimage(board[positiony][positionx].x - 22, board[positiony][positionx].y - 30, &black, SRCAND);
	//������Ϊ�������ӵ��������ڸ���ϣ��������ֵ�����ӵ���ͼ����

	return 1;//��ʾ���ӳɹ�
}