//���ߣ�����
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
	//�ѻ��渴������
	copyshoushu = shoushu;
	//��������Ϣ��������
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			copy[i][j] = gameboard[i][j];
	//�����̸�������
}
void reset()
{
	copyshoushu=shoushu = 0;
	//�������
	jnow = inow = -2;
	//�����������ʾ�������㷨�й�
	getimage(&fuzhipan, 0, 0, 0, 0);
	//���ͼ��
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			gameboard[i][j]=copy[i][j] = 0;
	//�������
}
void huiqi() {
	putimage(0, 0, &fuzhipan);
	//�Ѹ��ƵĻ�������ȥ
	shoushu=copyshoushu;
	//�����������Ƶ�����ͬ����
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			gameboard[i][j] = copy[i][j];
	//�Ѹ��Ƶ����̶���ȥ
}