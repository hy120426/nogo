#pragma once "qipan.h"
#define a hasqi
int tizi_b;
bool tizi_no(int i, int j, int yuan) {
	tizi_b = 0;
	tizi(i, j, yuan);
	if (!tizi_b) return 0;
	tizi_b = 0;
	if (a[i + 1][j]) { tizi(i + 1, j, a[i + 1][j]); if (!tizi_b) return 0; }
	tizi_b = 0;
	if (a[i - 1][j]) { tizi(i - 1, j, a[i - 1][j]); if (!tizi_b) return 0; }
	tizi_b = 0;
	if (a[i][j + 1]) { tizi(i, j + 1, a[i][j + 1]); if (!tizi_b) return 0; }
	tizi_b = 0;
	if (a[i][j - 1]) { tizi(i, j - 1, a[i][j - 1]); if (!tizi_b) return 0; }
	return 1;
}
void tizi(int row, int col, int yuan) {
	if (a[row][col] == 0) { tizi_b++; return; }
	if (a[row][col] != yuan) return;
	int kir = a[row][col];
	a[row][col] = 3;
	if (row > 1) tizi(row - 1, col, kir);
	if (col > 1) tizi(row, col - 1, kir);
	if (row < 9) tizi(row + 1, col, kir);
	if (col < 9) tizi(row, col + 1, kir);
	a[row][col] = kir;
	return;
}