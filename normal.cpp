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
		}//遍历每一个点计算黑棋禁入点的数目

	int v1 = 0;

	for (int i1 = 1; i1 <= 9; i1++)
		for (int j1 = 1; j1 <= 9; j1++) {
			if (!gameboard[i1][j1]) {
				gameboard[i1][j1] = 2;
				if (!tizi_no(i1, j1, 2))
					v1++;
				gameboard[i1][j1] = 0;
			}
		}//白棋禁入点的数目
	return v2 - v1; //作差
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
	if (dep <= deepnormal) { //深度小于限度，继续搜索
		int ans = 100000;
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++) {
				if (!gameboard[i][j]) { //如果这一点没有子
					gameboard[i][j] = 1; //模拟成黑棋
					if (tizi_no(i, j, 1)) { //如果没有造成提子
						int contenmp = value_2(dep + 1, ans); //计算价值
						//value_2这个函数跟1不同的只有，它模拟的是白棋，并且取得是最大值
						ans = ans<contenmp? ans: contenmp; //ans选择最小的一个
					}
					gameboard[i][j] = 0;
					if (ans <= kkkk) return ans;  //负极大值的剪枝，因为max(3,min(2,x))=3。
				}
			}
		return ans;
	}
	else return about_value(); //深度超过限度，估值
}
void xiaqi_normal() {
	shoushu++;
	deepnormal = 2;
	if (shoushu >= 20) deepnormal = 3;
	if (shoushu >= 33) deepnormal = 4;
	//随对局进行增大搜索深度
	if (shoushu > 100) deepnormal = 100;
	//这个用difficult难度的策略，暂时先不说
	to_be_chosen[0].value[0] = -1000000;
	//这个数组[0]表示预备下的点，[1]表示正在计算的点
	to_be_chosen[0].i = to_be_chosen[0].j = -1;

	//不是i和j从1~9去计算，而是右下->左下->右上->左上的计算顺序
	//这样的顺序，实际效果更有下棋的感觉
	//为演示方便，截图时只截计算右下的部分
	for (int i = 5; i <= 9; i++)
		for (int j = 5; j <= 9; j++) {
			if (!gameboard[i][j]) { //如果这一点没有棋子
				to_be_chosen[1].i = i; to_be_chosen[1].j = j; //记录ij坐标
				gameboard[i][j] = 2; //模拟为2棋子（白棋）
				if (tizi_no(i, j, 2)) { //如果没有产生提子
					to_be_chosen[1].value[0] = value_1(1, to_be_chosen[0].value[0]);//计算价值
				}
				else to_be_chosen[1].value[0] = -10000000; //否则，计价值为无限小
				if (to_be_chosen[1].value[0] > to_be_chosen[0].value[0]) to_be_chosen[0]=to_be_chosen[1];
				//如果该点的价值大于[0]候选点，将[0]变成它
				gameboard[i][j] = 0; //复原
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
