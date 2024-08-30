#include <stdio.h>

int map[51][51] = { 0, };
int chk[51][51] = { 0, };
int N = 0; int M = 0;

int move[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

typedef struct pos {
	int y;
	int x;
}pos;

int dp[51][51] = { 0, };

int infinite = 0;
int deepest = 0;
int ended = 0;

void simul(int time, pos nowpos) {
	dp[nowpos.y][nowpos.x] = time;

	if (infinite == 1) {
		return;
	}
	if (time > deepest) {
		deepest = time;
	}

	pos nxtpos = { 0, };
	pos dppos = { 0, };
	pos dpnxtpos = { 0, };
	int range = 0;
	range = map[nowpos.y][nowpos.x];

	for (int i = 0; i < 4; i++) {
		nxtpos.y = nowpos.y + move[i][0] * range;
		nxtpos.x = nowpos.x + move[i][1] * range;
			
		if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= M || nxtpos.x < 0) { // 범위초과
			continue;
		}
		if (map[nxtpos.y][nxtpos.x] == 0) { // 구멍
			continue;
		}
		if (dp[nxtpos.y][nxtpos.x] > time) {
			continue;
		}
		if (chk[nxtpos.y][nxtpos.x] == 1) {
			// 무한루프
			infinite = 1;
			return;
		}

		chk[nxtpos.y][nxtpos.x] = 1;
		simul(time + 1, nxtpos);
		chk[nxtpos.y][nxtpos.x] = 0;
		
		if (infinite == 1) {
			return;
		}
	}
	return;
}


int main() {
	scanf("%d %d", &N, &M);
	getchar();

	char tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1c", &tmp);

			if (tmp == 'H') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = tmp-48;
			}
		}
		getchar();
	} 

	pos nowpos;
	nowpos.x = 0; nowpos.y = 0;
	chk[0][0] = 1;
	simul(1, nowpos);

	if (infinite == 1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", deepest);
	}

	return 0;
}