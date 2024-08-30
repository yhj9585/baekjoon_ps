#include <stdio.h>
#pragma warning(disable:4996)

int N = 0;
int map[501][501] = { 0, };
int chk[501][501] = { 0, };

int move[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

int simul(int y, int x) {
	if (chk[y][x] != -1) {
		return chk[y][x];
	}

	int tmp = 0;
	int best = 0;

	int toY = 0; int toX = 0;
	for (int i = 0; i < 4; i++) {
		toY = y + move[i][0];
		toX = x + move[i][1];

		if (toY >= N || toY < 0 || toX >= N || toX < 0) {
			continue;
		}
		if (map[toY][toX] > map[y][x]) {
			tmp = simul(toY, toX);
			if (tmp > best) {
				best = tmp;
			}
		}
	}

	chk[y][x] = best + 1;
	return chk[y][x];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			chk[i][j] = -1;
		}
	}

	int best = 0;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp = simul(i, j);
			if (best < tmp) {
				best = tmp;
			}
		}
	}
	printf("%d\n", best);
	return 0;
}