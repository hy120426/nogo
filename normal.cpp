//���ߣ�����
#include "normal.h"
#include "tizino.h"
#include "jiegouti.h"
#include<easyx.h>
#include<iostream>


using namespace std;
int shoushu = 0;
int deepnormal=2;
extern int gameboard[11][11];
//extern const int deep;
extern int inow, jnow;
extern IMAGE bk;
extern IMAGE white;
extern IMAGE tip;
qi to_be_chosen[2];
extern position board[9][9];

int about_value() {
	int v2 = 0;

	for (int i1 = 1; i1 <= 9; i1++)
		for (int j1 = 1; j1 <= 9; j1++) {
			if (!gameboard[i1][j1]) {
				gameboard[i1][j1] = 1;
				if (!tizi_no(i1, j1, 1))
					v2++;
				gameboard[i1][j1] = 0;
			}
		}//����ÿһ�����������������Ŀ

	int v1 = 0;

	for (int i1 = 1; i1 <= 9; i1++)
		for (int j1 = 1; j1 <= 9; j1++) {
			if (!gameboard[i1][j1]) {
				gameboard[i1][j1] = 2;
				if (!tizi_no(i1, j1, 2))
					v1++;
				gameboard[i1][j1] = 0;
			}
		}//�����������Ŀ
	return v2 - v1; //����
}
int value_2(int dep,int llll) {
	if (dep <= deepnormal) {
		int ans = -100000;
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++) {
				if (!gameboard[i][j]) {
					gameboard[i][j] = 2;
					if (tizi_no(i, j, 2)) {
						int contenmp= value_1(dep + 1,ans);
						ans = ans> contenmp ? ans: contenmp;
					}
					gameboard[i][j] = 0;
					if (ans >= llll) return ans;
				}
			}
		return ans;
	}
	else return about_value();
}
int value_1(int dep,int kkkk) {
	if (dep <= deepnormal) { //���С���޶ȣ���������
		int ans = 100000;
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++) {
				if (!gameboard[i][j]) { //�����һ��û����
					gameboard[i][j] = 1; //ģ��ɺ���
					if (tizi_no(i, j, 1)) { //���û���������
						int contenmp = value_2(dep + 1, ans); //�����ֵ
						//value_2���������1��ͬ��ֻ�У���ģ����ǰ��壬����ȡ�������ֵ
						ans = ans<contenmp? ans: contenmp; //ansѡ����С��һ��
					}
					gameboard[i][j] = 0;
					if (ans <= kkkk) return ans;  //������ֵ�ļ�֦����Ϊmax(3,min(2,x))=3��
				}
			}
		return ans;
	}
	else return about_value(); //��ȳ����޶ȣ���ֵ
}
void xiaqi_normal() {
	shoushu++;
	deepnormal = 2;
	if (shoushu >= 20) deepnormal = 3;
	if (shoushu >= 33) deepnormal = 4;
	//��Ծֽ��������������
	if (shoushu > 100) deepnormal = 100;
	//�����difficult�ѶȵĲ��ԣ���ʱ�Ȳ�˵
	to_be_chosen[0].value[0] = -1000000;
	//�������[0]��ʾԤ���µĵ㣬[1]��ʾ���ڼ���ĵ�
	to_be_chosen[0].i = to_be_chosen[0].j = -1;

	//����i��j��1~9ȥ���㣬��������->����->����->���ϵļ���˳��
	//������˳��ʵ��Ч����������ĸо�
	//Ϊ��ʾ���㣬��ͼʱֻ�ؼ������µĲ���
	for (int i = 5; i <= 9; i++)
		for (int j = 5; j <= 9; j++) {
			if (!gameboard[i][j]) { //�����һ��û������
				to_be_chosen[1].i = i; to_be_chosen[1].j = j; //��¼ij����
				gameboard[i][j] = 2; //ģ��Ϊ2���ӣ����壩
				if (tizi_no(i, j, 2)) { //���û�в�������
					to_be_chosen[1].value[0] = value_1(1, to_be_chosen[0].value[0]);//�����ֵ
				}
				else to_be_chosen[1].value[0] = -10000000; //���򣬼Ƽ�ֵΪ����С
				if (to_be_chosen[1].value[0] > to_be_chosen[0].value[0]) to_be_chosen[0]=to_be_chosen[1];
				//����õ�ļ�ֵ����[0]��ѡ�㣬��[0]�����
				gameboard[i][j] = 0; //��ԭ
			}
		}
	for (int i = 5; i <= 9; i++)
		for (int j = 1; j <= 4; j++) {
			if (!gameboard[i][j]) {
				to_be_chosen[1].i = i; to_be_chosen[1].j = j;
				gameboard[i][j] = 2;
				if (tizi_no(i, j, 2)) {
					to_be_chosen[1].value[0] = value_1(1, to_be_chosen[0].value[0]);
				}
				else to_be_chosen[1].value[0] = -10000000;
				if (to_be_chosen[1].value[0] > to_be_chosen[0].value[0]) std::swap(to_be_chosen[0], to_be_chosen[1]);
				gameboard[i][j] = 0;
			}
		}
	for (int i = 1; i <= 4; i++)
		for (int j = 5; j <= 9; j++) {
			if (!gameboard[i][j]) {
				to_be_chosen[1].i = i; to_be_chosen[1].j = j;
				gameboard[i][j] = 2;
				if (tizi_no(i, j, 2)) {
					to_be_chosen[1].value[0] = value_1(1, to_be_chosen[0].value[0]);
				}
				else to_be_chosen[1].value[0] = -10000000;
				if (to_be_chosen[1].value[0] > to_be_chosen[0].value[0]) std::swap(to_be_chosen[0], to_be_chosen[1]);
				gameboard[i][j] = 0;
			}
		}
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++) {
			if (!gameboard[i][j]) {
				to_be_chosen[1].i = i; to_be_chosen[1].j = j;
				gameboard[i][j] = 2;
				if (tizi_no(i, j, 2)) {
					to_be_chosen[1].value[0] = value_1(1, to_be_chosen[0].value[0]);
				}
				else to_be_chosen[1].value[0] = -10000000;
				if (to_be_chosen[1].value[0] > to_be_chosen[0].value[0]) std::swap(to_be_chosen[0], to_be_chosen[1]);
				gameboard[i][j] = 0;
			}
		}
	inow = to_be_chosen[0].i; jnow = to_be_chosen[0].j;
	gameboard[inow][jnow] = 2;
	putimage(board[inow -1][jnow -1].x - 22, board[inow - 1][jnow - 1].y - 30, &bk, SRCPAINT);
	putimage(board[inow -1][jnow -1].x - 22, board[inow - 1][jnow - 1].y - 30, &tip, SRCAND);
}
