//���ߣ�������
//���ļ�������ģʽ������㷨
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
extern random_device rd;//�����������������

void xiaqi_easy() {
	memset(oki, 0, sizeof(oki));//��ʾ�������iλ��
	memset(okj, 0, sizeof(okj));//��ʾ�������jλ��
	oknum = 0;//��ʾ�������λ�ø���
	bool finish = true;//ָʾ��Ϸ�Ƿ�����ı���
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {//����������ijλ���ܷ������
			if (gameboard[i][j] == 0) {
				gameboard[i][j] = 2;
				if (tizi_no(i, j, 2)) {
					finish = false;
					oki[oknum] = i;
					okj[oknum] = j;//ÿ��oknum���Զ�Ӧһ��ijֵ
					oknum++;
				}gameboard[i][j] = 0;
			}
		}
	}
	if (finish) {//���finishֵΪtrue����Ϸ����
		jnow = -1; return;
	}
	else {
		mt19937 randomok(rd());//�����������
		uniform_int_distribution<int> dis(0, oknum - 1);//�ڿ����µ�λ���������һ��λ��
		int x = dis(randomok);
		inow = oki[x];
		jnow = okj[x];
		gameboard[inow][jnow] = 2;
		putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &bk, SRCPAINT);
		putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &tip, SRCAND);//�������ͼ
	}
}
