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
bool tizi_no(int i, int j, int yuan)//yuan表示棋子的颜色
{
	tizi_judge = 0;

	tizi(i, j, yuan);
	//这个函数判断此位置的棋子有没有被提掉，如果没有，它会把tizi_judge这个整型变量变成大于0的数

	if (!tizi_judge) return 0; //如果tizi_judge还是0，那就说明产生了提子，直接返回0
	tizi_judge = 0;//否则先把tizi_judge变回0

	if (gameboard[i + 1][j]) { tizi(i + 1, j, gameboard[i + 1][j]); if (!tizi_judge) return 0; }
	tizi_judge = 0;
	if (gameboard[i - 1][j]) { tizi(i - 1, j, gameboard[i - 1][j]); if (!tizi_judge) return 0; }
	tizi_judge = 0;
	if (gameboard[i][j + 1]) { tizi(i, j + 1, gameboard[i][j + 1]); if (!tizi_judge) return 0; }
	tizi_judge = 0;
	if (gameboard[i][j - 1]) { tizi(i, j - 1, gameboard[i][j - 1]); if (!tizi_judge) return 0; }
	//判断上下左右四个方向是否有提子

	return 1;//都没有，就return 1
}

void tizi(int row, int col, int yuan)
{
	if (gameboard[row][col] == 0) { tizi_judge++; return; }
	//这个函数要不断经过递归调用的，递归到这里是0，就说明这块棋有气
	//有气就没死，就不是被提子的棋，所以给tizi_judge++，然后return

	if (gameboard[row][col] != yuan) return;
	//撞到了另一个颜色的棋子，这一点就不是它的气了，直接返回

	int kir = gameboard[row][col];
	//这一点原来的状态记录下来

	gameboard[row][col] = 3; //令其为3，避免死循环反复数

	if (row > 1) tizi(row - 1, col, kir);
	if (col > 1) tizi(row, col - 1, kir);
	if (row < 9) tizi(row + 1, col, kir);
	if (col < 9) tizi(row, col + 1, kir);
	//四个方向分别走一遍

	gameboard[row][col] = kir;
	//还原
	return;
}
