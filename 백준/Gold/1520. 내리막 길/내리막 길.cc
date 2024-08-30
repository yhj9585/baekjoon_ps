#include <stdio.h>
#pragma warning(disable:4996)

int M = 0; int N = 0;
int map[501][501] = { 0, };
int chk[501][501] = { 0, };

int move[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

int simul(int y, int x) {
	if (y == M - 1 && x == N - 1) {
		return 1;
	}
	if (chk[y][x] != -1) {
		return chk[y][x];
	}

	int cango = 0;

	int toY = 0; int toX = 0;
	for (int i = 0; i < 4; i++) {
		toY = y + move[i][0];
		toX = x + move[i][1];

		if (toY > M || toY < 0 || toX >= N || toX < 0) {
			continue;
		}
		if (map[toY][toX] < map[y][x]) {
			cango += simul(toY, toX);
		}
	}

	chk[y][x] = cango;
	return cango;
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			chk[i][j] = -1;
		}
	}

	printf("%d\n", simul(0, 0));
	return 0;
}