#include <stdio.h>
#pragma warning(disable:4996)

int N, M;
int top;
int map[51][51];
int visit[51][51];

typedef struct pos {
	int y, x; 
}pos;

pos move[4] = {
	{-1,  0},
	{ 1,  0},
	{ 0, -1},
	{ 0,  1}
};

pos queue[2600];
int st, ed;

void push(pos nxt) {
	queue[ed++] = nxt;
	return;
}

pos pop() {
	return queue[st++];
}

int size() {
	return ed - st;
}

int test(pos npos, int water) {
	if (npos.x > 0 && npos.x < M - 1 && npos.y > 0 && npos.y < N - 1) {
		if (visit[npos.y][npos.x] != water) {
			if (map[npos.y][npos.x] < water) {
				return 1;
			}
		}
	}
	else {
		if (map[npos.y][npos.x] < water) {
			return 2; // not pool
		}
	}
	return 0;
}

void bfs() {

	pos firpos;
	pos npos;
	pos nxtpos;
	int pool = 1;
	int poolsize = 0;
	int total = 0;


	for (int water = 2; water <= top; water++) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				firpos.x = j;
				firpos.y = i;
				if (test(firpos, water) == 1) {
					push(firpos);
					poolsize++;
					visit[firpos.y][firpos.x] = water;
				}
				while (size() != 0) {
					npos = pop();

					for (int m = 0; m < 4; m++) {
						nxtpos.x = npos.x + move[m].x;
						nxtpos.y = npos.y + move[m].y;

						if (test(nxtpos, water) == 1) {
							push(nxtpos);
							poolsize++;
							visit[nxtpos.y][nxtpos.x] = water;
						}
						else if (test(nxtpos, water) == 2) {
							pool = 0;
						}
					}
				}
				st = 0;
				ed = 0;
				if (pool == 1) {
					total += poolsize;
				}
				pool = 1;
				poolsize = 0;
			}
		}
		if (pool == 0) {
			break;
		}

	}

	printf("%d", total);

}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] > top) {
				top = map[i][j];
			}
		}
	}

	bfs();

	return 0;
}