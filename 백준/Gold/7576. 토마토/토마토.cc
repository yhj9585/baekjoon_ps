#include <stdio.h>
#pragma warning(disable: 4996)

int N, M;

struct pos {
	int x, y;
};

pos move[4] = {
	{-1,  0},
	{ 1,  0},
	{ 0, -1},
	{ 0,  1}
};

int map[1005][1005];

// queue //
pos queue[1000005];
int st, ed;

void push(pos n) {
	queue[ed++] = n;
	return;
}

pos pop() {
	return queue[st++];
}

int size() {
	return ed - st;
}

void reset() {
	ed = 0;
	st = 0;
	return;
}

pos nxt(pos n, int i) {
	pos nxt_pos;
	nxt_pos.x = n.x + move[i].x;
	nxt_pos.y = n.y + move[i].y;
	return nxt_pos;
}

int able(pos n) {
	if (n.x >= 0 && n.y >= 0 && n.x < M && n.y < N) {
		if (map[n.y][n.x] == 0) {
			return 1;
		}
	}
	return 0;
}

void bfs() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				push({ j, i });
			}
		}
	}

	pos n_pos;
	pos nxt_pos;

	while (size() != 0) {
		n_pos = pop();

		for (int i = 0; i < 4; i++) {
			nxt_pos = nxt(n_pos, i);

			if (able(nxt_pos)) {
				push(nxt_pos);
				map[nxt_pos.y][nxt_pos.x] = map[n_pos.y][n_pos.x] + 1;
			}
		}
	}
}

void chk() {
	
	int large = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > large) {
				large = map[i][j];
			}
			if (map[i][j] == 0) {
				printf("-1\n");
				return;
			}
		}
	}


	printf("%d\n", large - 1);


	return;
}


int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	bfs();
	chk();

	return 0;
}
