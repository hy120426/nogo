//���ߣ�������
//���ļ���������������ʾ�ĺ���
#include<easyx.h>
#include"tip.h"
#include "jiegouti.h"
extern int inow, jnow, copyi, copyj;
extern IMAGE bk, white;
extern position board[9][9];
void returnwhite() {//���ڵ�������ʱ����ͼΪ��ɫ���������������ɫ���Ӹ���Ϊ��ɫ
	if (inow != -2) {//inow=-2Ϊ��ʼ״̬��Ҳ���ǵ�һ������һ��û�С�ǰһ����
		putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &bk, SRCPAINT);
		putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &white, SRCAND);
		//inow��jnow��¼�˵�������һ�����ӵ�λ��
	}
}
void huiqireturn() {//���ڴ������ʱ������ʾ������
	if (inow == -2)return;
	putimage(board[copyi - 1][copyj - 1].x - 22, board[copyi - 1][copyj - 1].y - 30, &bk, SRCPAINT);
	putimage(board[copyi - 1][copyj - 1].x - 22, board[copyi - 1][copyj - 1].y - 30, &white, SRCAND);
	inow = copyi; jnow = copyj;//copyi��copyj���ڼ�¼���Ե����ڶ������ӵ�λ��
}