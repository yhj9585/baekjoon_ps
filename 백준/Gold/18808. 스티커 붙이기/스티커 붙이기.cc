#include <stdio.h>
#pragma warning(disable:4996)

int N = 0; int M = 0;
int map[41][41] = { 0, };

int tileleft = 0;

int K = 0;
int size[101][2] = { 0, };
int stickersize[101] = { 0, };
int sticker[101][11][11] = { 0, };

void turn90degree(int R, int C, int rotate[][11]) {
	// turn 90 degree
	int newrotate[11][11] = { 0, };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			newrotate[j][R - 1 - i] = rotate[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			rotate[i][j] = 0;
		}
	}


	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			rotate[i][j] = newrotate[i][j];
		}
	}

	return;
}

void simul() {
	int availble = 0;
	int R = 0;
	int C = 0;

	for (int stk = 0; stk < K; stk++) {
		int thistk[11][11] = { 0, };
		R = size[stk][0];
		C = size[stk][1];

		if (tileleft < stickersize[stk]) {
			continue;
		}


		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				thistk[i][j] = sticker[stk][i][j];
			}
		}

		for (int turn = 0; turn < 4; turn++) {
			availble = 1;

			if (turn % 2 == 0) {
				R = size[stk][0];
				C = size[stk][1];
			}
			else {
				R = size[stk][1];
				C = size[stk][0];
			}

			if (R > N || C > M) {
				turn90degree(R, C, thistk);
				continue;
			}


			for (int i = 0; i <= N - R; i++) {
				for (int j = 0; j <= M - C; j++) {

					availble = 1;
					for (int y = 0; y < R; y++) {
						for (int x = 0; x < C; x++) {
							if (map[y+i][x+j] != 0 && thistk[y][x] == 1) {
								availble = 0;
							}
						}
					}
					if (availble == 1) {
						for (int y = 0; y < R; y++) {
							for (int x = 0; x < C; x++) {
								if (thistk[y][x] == 1) {
									map[y + i][x + j] = 1;
								}
							}
						}
						tileleft -= stickersize[stk];
						break;
					}
				}
				if (availble == 1) {
					break;
				}
			}



			if (availble == 1) {
				availble = 0;
				break;
			}
			else {
				turn90degree(R, C, thistk);
			}
		}


	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	tileleft = N * M;

	int cnt = 0;
	
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &size[i][0], &size[i][1]);
		cnt = 0;

		for (int y = 0; y < size[i][0]; y++) {
			for (int x = 0; x < size[i][1]; x++) {
				scanf("%d", &sticker[i][y][x]);
				if (sticker[i][y][x] == 1) {
					cnt++;
				}
			}
		}
		stickersize[i] = cnt;
	}

	simul();
	printf("%d\n", N * M - tileleft);

	return 0;
}