//���ߣ�����
#include "tizino.h"

int tizi_judge=0;
extern int gameboard[11][11];
bool supertizi_no(int b[11][11], int i, int j, int yuan)
{
	tizi_judge = 0;
	b[i][j] = yuan;
	supertizi(b, i, j, yuan);
	if (!tizi_judge) { b[i][j] = 0; return 0; }
	tizi_judge = 0;
	if (b[i + 1][j]) { supertizi(b, i + 1, j, b[i + 1][j]); if (!tizi_judge) { b[i][j] = 0; return 0; } }
	tizi_judge = 0;
	if (b[i - 1][j]) { supertizi(b, i - 1, j, b[i - 1][j]); if (!tizi_judge) { b[i][j] = 0; return 0; } }
	tizi_judge = 0;
	if (b[i][j + 1]) { supertizi(b, i, j + 1, b[i][j + 1]); if (!tizi_judge) { b[i][j] = 0; return 0; } }
	tizi_judge = 0;
	if (b[i][j - 1]) { supertizi(b, i, j - 1, b[i][j - 1]); if (!tizi_judge) { b[i][j] = 0; return 0; } }
	b[i][j] = 0;
	return 1;
}
void supertizi(int b[11][11],int row, int col, int yuan)
{
	if (b[row][col] == 0) { tizi_judge++; return; }
	if (b[row][col] != yuan) return;
	int kir = b[row][col];
	b[row][col] = 3;
	if (row > 1) supertizi(b,row - 1, col, kir);
	if (col > 1) supertizi(b,row, col - 1, kir);
	if (row < 9) supertizi(b,row + 1, col, kir);
	if (col < 9) supertizi(b,row, col + 1, kir);
	b[row][col] = kir;
	return;
}
bool tizi_no(int i, int j, int yuan)//yuan��ʾ���ӵ���ɫ
{
	tizi_judge = 0;

	tizi(i, j, yuan);
	//��������жϴ�λ�õ�������û�б���������û�У������tizi_judge������ͱ�����ɴ���0����

	if (!tizi_judge) return 0; //���tizi_judge����0���Ǿ�˵�����������ӣ�ֱ�ӷ���0
	tizi_judge = 0;//�����Ȱ�tizi_judge���0

	if (gameboard[i + 1][j]) { tizi(i + 1, j, gameboard[i + 1][j]); if (!tizi_judge) return 0; }
	tizi_judge = 0;
	if (gameboard[i - 1][j]) { tizi(i - 1, j, gameboard[i - 1][j]); if (!tizi_judge) return 0; }
	tizi_judge = 0;
	if (gameboard[i][j + 1]) { tizi(i, j + 1, gameboard[i][j + 1]); if (!tizi_judge) return 0; }
	tizi_judge = 0;
	if (gameboard[i][j - 1]) { tizi(i, j - 1, gameboard[i][j - 1]); if (!tizi_judge) return 0; }
	//�ж����������ĸ������Ƿ�������

	return 1;//��û�У���return 1
}

void tizi(int row, int col, int yuan)
{
	if (gameboard[row][col] == 0) { tizi_judge++; return; }
	//�������Ҫ���Ͼ����ݹ���õģ��ݹ鵽������0����˵�����������
	//������û�����Ͳ��Ǳ����ӵ��壬���Ը�tizi_judge++��Ȼ��return

	if (gameboard[row][col] != yuan) return;
	//ײ������һ����ɫ�����ӣ���һ��Ͳ����������ˣ�ֱ�ӷ���

	int kir = gameboard[row][col];
	//��һ��ԭ����״̬��¼����

	gameboard[row][col] = 3; //����Ϊ3��������ѭ��������

	if (row > 1) tizi(row - 1, col, kir);
	if (col > 1) tizi(row, col - 1, kir);
	if (row < 9) tizi(row + 1, col, kir);
	if (col < 9) tizi(row, col + 1, kir);
	//�ĸ�����ֱ���һ��

	gameboard[row][col] = kir;
	//��ԭ
	return;
}
