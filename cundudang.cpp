//���ߣ�����
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
	//ͨ��һ���ĵ����������ϵ�ÿһ�����״̬
	getimage(&cundangzhiqian,0,0,1200,675); 
	//�Ѵ浵֮ǰ�Ļ����ȱ�������
	putimage(426, 200, &baocun);
	//����Ļ����ʾ������ɹ���������
	Sleep(600);
	//�������������0.6��
	putimage(0, 0, &cundangzhiqian);
	//��֮ǰ����õĻ����ٷ���ȥ������
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
	//���ĵ����ݶ�������shoushu�����Ǹ������㷨�йص�һ����
	//����֮��ȻҲҪͬ������
	shoushu /= 2;
}