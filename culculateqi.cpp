//���ߣ�����
#include "culculateqi.h"
#include "tizino.h"
#include "jiegouti.h"
#include<easyx.h>
#include<iostream>
#include"normal.h"



using namespace std;

extern int gameboard[11][11];
extern const int deep;
extern int jnow;
extern int inow;
extern IMAGE bk;
extern IMAGE white;
extern IMAGE tip;
extern qi kkt[2];
extern int shoushu;
extern position board[9][9];

struct valuejudge {
	int qipan[11][11] = {};
	int i = -1;
	int j = -1;
	int value = 0;
	valuejudge* next = NULL;
	valuejudge* prev = NULL;
};
valuejudge* head[10] = {};
valuejudge* tail[10] = {};
int maxdep[10] = {};

class copypan {
public:
	int pan[11][11] = {};
	void copyqipan(copypan*);
	void initpan();
	void grow();
	bool check();
};
void copypan::copyqipan(copypan* father) {
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (father->pan[i][j]) this->pan[i][j] = 3;
} //�̳���һ����������
void copypan::initpan() {
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (gameboard[i][j])
				this->pan[i][j] = 3;
}//�Ȱѵ�һ������ǰ����Ū����
void copypan::grow() {
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++) {
			if (this->pan[i][j] == 3) {
				this->pan[i + 1][j] = this->pan[i + 1][j] == 3 ? 3 : 4;
				this->pan[i - 1][j] = this->pan[i - 1][j] == 3 ? 3 : 4;
				this->pan[i][j + 1] = this->pan[i][j + 1] == 3 ? 3 : 4;
				this->pan[i][j - 1] = this->pan[i][j - 1] == 3 ? 3 : 4;
			}
		}
}//��������
bool copypan::check() {
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (this->pan[i][j] == 0) return 1; //���пո�
	return 0;
}//�������̻���û�п��ŵĵ�
void dasan() {
	copypan pan1[100]; //��һϵ�е�������׼���Ŀռ�
	pan1[0].initpan();
	int i = 1;
	for (i = 1; 1; i++) {
		copypan* father = &pan1[i - 1];
		pan1[i].copyqipan(father);
		pan1[i].grow();
		if (!pan1[i].check()) break; //û�пյĵ��˾Ͳ���������
	}
	int sanmax = i - 1; //��ʱ����һ���������̵Ŀ��µĵ�������������ĵ�
	position kexuan[82]; //����ô���ѡ�ĵ�
	int kexuancounter = 0;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++) {
			if (!pan1[sanmax].pan[i][j]) {
				kexuan[kexuancounter].y = i;
				kexuan[kexuancounter].x = j;
				kexuancounter++;
			}
		} //�ѿ�ѡ�ĵ��¼����
	srand((unsigned)time(NULL) + 1);
	int xuanzhong = rand() % kexuancounter;
	inow = kexuan[xuanzhong].y;
	jnow = kexuan[xuanzhong].x; //Ȼ��ȥ���ѡ��
	gameboard[inow][jnow] = 2;

	putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &bk, SRCPAINT);
	putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &tip, SRCAND);
}

void xiaqi_difficult() {
	if (shoushu > 33) { shoushu = 101; xiaqi_normal(); return; }
	//���̽��и�����ֵ����
	shoushu++;
	for (int i = 1; i <= deep; i++) maxdep[i] = 0;
	//maxdep[i]�����ʾ��i�������ֵ�Ƕ��٣������������г�ʼ��
	head[1] = new valuejudge; 
	//����ṹ���а���һ�����̣�һ�������ꡢһ��������
	//һ����ֵ������ǰ��ָ��
	tail[1] = head[1];
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (!gameboard[i][j]) //����õ�û������
				if(supertizi_no(gameboard, i, j, 2))//����������Ӳ���������� 
				{
				int current = valuepoint(gameboard, i, j);
				//����õ�ļ�ֵ
				if (current == maxdep[1]) { //����뵱ǰ������ֵ��ȣ���������β
					tail[1]->next = new valuejudge;
					tail[1]->next->prev = tail[1];
					tail[1] = tail[1]->next;
					tail[1]->i = i;
					tail[1]->j = j;
					for (int ii = 1; ii <= 9; ii++)
						for (int jj = 1; jj <= 9; jj++) {
							tail[1]->qipan[ii][jj] = gameboard[ii][jj];
						}
					tail[1]->qipan[i][j] = 2;
					tail[1]->value = current;
				}
				if (current > maxdep[1]) {  
					//������ڵ�ǰ����ֵ����������ֵ����Ϊ�µ�����ͷ
					//delete֮ǰ���ڴ�
					maxdep[1] = current;
					while (head[1] != tail[1]) {
						head[1] = head[1]->next;
						delete head[1]->prev;
					}
					delete head[1];
					head[1] = new valuejudge;
					tail[1] = head[1];
					head[1]->i = i;
					head[1]->j = j;
					head[1]->value = current;
					for (int ii = 1; ii <= 9; ii++)
						for (int jj = 1; jj <= 9; jj++)
							head[1]->qipan[ii][jj] = gameboard[ii][jj];
					head[1]->qipan[i][j] = 2;
				}
			}
	if (maxdep[1] == 0) { dasan(); return; }
	if (head[1] == tail[1]) { inow = head[1]->i; jnow = head[1]->j; } 
	//�����ֵ����Ψһ���Ǿ�ѡȡ��
	else {//����ȥ������ֵ
		value1(2); //��������Ĳ������������ݴ�ͬС�죬������ϸ����
		//Ψһ��������"����ֵ���Ƿ�Ψһ"���жϷ�ʽ
	}
	gameboard[inow][jnow] = 2;

	putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &bk, SRCPAINT);
	putimage(board[inow - 1][jnow - 1].x - 22, board[inow - 1][jnow - 1].y - 30, &tip, SRCAND);
}

void value1(int depth) {
	if (depth > deep) { inow = head[depth - 1]->i; jnow = head[depth - 1]->j; return; }
	head[depth] = new valuejudge;
	tail[depth] = head[depth];
	valuejudge* ima = head[depth - 1];
	while (ima) {
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
				if (!ima->qipan[i][j])
					if(supertizi_no(ima->qipan, i, j, 1)) {
					int current = valuepoint(ima->qipan, i, j);

					if (current == maxdep[depth]) {
						tail[depth]->next = new valuejudge;
						tail[depth]->next->prev = tail[depth];
						tail[depth] = tail[depth]->next;
						tail[depth]->i = ima->i;
						tail[depth]->j = ima->j;
						for (int ii = 1; ii <= 9; ii++)
							for (int jj = 1; jj <= 9; jj++)
								tail[depth]->qipan[ii][jj] = ima->qipan[ii][jj];
						tail[depth]->qipan[i][j] = 1;
					}

					if (current > maxdep[depth]) {
						maxdep[depth] = current;
						//deleteǰ���
						while (head[depth] != tail[depth]) {
							head[depth] = head[depth]->next;
							delete head[depth]->prev;
						}
						delete head[depth];
						head[depth] = new valuejudge;
						tail[depth] = head[depth];
						head[depth]->i = ima->i;
						head[depth]->j = ima->j;
						for (int ii = 1; ii <= 9; ii++)
							for (int jj = 1; jj <= 9; jj++)
								head[depth]->qipan[ii][jj] = ima->qipan[ii][jj];
						head[depth]->qipan[i][j] = 1;
					}
				}
		ima = ima->next;
	}
	if (head[depth]->i == -1) { inow = head[depth - 1]->i; jnow = head[depth - 1]->j; return; }
	bool weiyi = 1;
	valuejudge* check = head[depth];
	while (check->next) {
		if (check->i != check->next->i || check->j != check->next->j) { weiyi = 0; break; }
		check = check->next;
	}
	//���deep1�������ͷ��β��������궼��һ���ģ���ô��Ϊ����ֵ���Ѿ�Ψһ
	if (weiyi) { inow = head[depth]->i; jnow = head[depth]->j; return; }
	else { value2(depth + 1); return; }
}
void value2(int depth) {
	if (depth > deep) { inow = head[depth - 1]->i; jnow = head[depth - 1]->j; return; }
	head[depth] = new valuejudge;
	tail[depth] = head[depth];
	valuejudge* ima = head[depth - 1];
	while (ima) {
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
				if (!ima->qipan[i][j])
					if(supertizi_no(ima->qipan, i, j, 2)) {
					int current = valuepoint(ima->qipan, i, j);

					if (current == maxdep[depth]) {
						tail[depth]->next = new valuejudge;
						tail[depth]->next->prev = tail[depth];
						tail[depth] = tail[depth]->next;
						tail[depth]->i = ima->i;
						tail[depth]->j = ima->j;
						for (int ii = 1; ii <= 9; ii++)
							for (int jj = 1; jj <= 9; jj++)
								tail[depth]->qipan[ii][jj] = ima->qipan[ii][jj];
						tail[depth]->qipan[i][j] = 2;
					}

					if (current > maxdep[depth]) {
						maxdep[depth] = current;
						//deleteǰ���
						while (head[depth]!=tail[depth]) {
							head[depth] = head[depth]->next;
							delete head[depth]->prev;
						}
						delete head[depth];
						head[depth] = new valuejudge;
						tail[depth] = head[depth];
						head[depth]->i = ima->i;
						head[depth]->j = ima->j;
						for (int ii = 1; ii <= 9; ii++)
							for (int jj = 1; jj <= 9; jj++)
								head[depth]->qipan[ii][jj] = ima->qipan[ii][jj];
						head[depth]->qipan[i][j] = 2;
					}
				}
		ima = ima->next;
	}
	if (head[depth]->i == -1) { inow = head[depth - 1]->i; jnow = head[depth - 1]->j; return; }
	bool weiyi = 1;
	valuejudge* check = head[depth];
	while (check->next) {
		if (check->i != check->next->i || check->j != check->next->j) { weiyi = 0; break; }
		check = check->next;
	}
	if (weiyi) { inow = head[depth]->i; jnow = head[depth]->j; return; }
	else { value1(depth + 1); return; }
}
int valuepoint(int b[11][11], int i, int j) {
	int ans = 0;
	if (supertizi_no(b, i, j, 2)) {
		b[i][j] = 2;
		for (int ii = 1; ii <= 9; ii++)
			for (int jj = 1; jj <= 9; jj++) {
				if(!b[ii][jj])
				if (!supertizi_no(b, ii, jj, 1)) ans++;
			}
	}
	if (supertizi_no(b, i, j, 1)) {
		b[i][j] = 1;
		for (int ii = 1; ii <= 9; ii++)
			for (int jj = 1; jj <= 9; jj++) {
				if(!b[ii][jj])
				if (!supertizi_no(b, ii, jj, 2)) ans++;
			}
	}
	b[i][j] = 0;
	return ans;
}