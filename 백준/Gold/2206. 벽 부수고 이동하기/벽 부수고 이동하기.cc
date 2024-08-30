#include <iostream>
#pragma warning (disable: 4996)

struct pos {
	int x, y;
	int depth;
	int breakable;
};


pos move[4] = {
	{ -1,  0 },
	{  1,  0 },
	{  0, -1 },
	{  0,  1 },
};

int N, M;
int map[1001][1001] = { 0, };
int visit[2][1001][1001] = { 0, };

pos nxt_move(pos n, int i) {
	pos nxt_n;
	nxt_n.x = n.x + move[i].x;
	nxt_n.y = n.y + move[i].y;
	nxt_n.depth = n.depth + 1;
	nxt_n.breakable = n.breakable;
	return nxt_n;
}


pos queue[2000000] = { 0, };
int st, ed;

void push(pos n) {
	queue[ed++] = n;
}
pos pop() {
	return queue[st++];
}
int empty() {
	return ed - st;
}


void bfs() {
	visit[0][0][0] = 1;
	push({ 0, 0, 1, 1 });

	while (empty() > 0) {
		pos n_pos = pop();

		if (n_pos.x == M - 1 && n_pos.y == N - 1) {
			printf("%d", n_pos.depth);
			return;
		}

		for (int i = 0; i < 4; i++) {
			pos nxt_pos = nxt_move(n_pos, i);

			if (nxt_pos.y < N && nxt_pos.x < M && nxt_pos.y >= 0 && nxt_pos.x >= 0) {
				if (nxt_pos.breakable == 0)
					if (map[nxt_pos.y][nxt_pos.x] == 0 && visit[1][nxt_pos.y][nxt_pos.x] == 0) {
					push(nxt_pos);
					visit[1][nxt_pos.y][nxt_pos.x] = 1;
				}
				
				if (nxt_pos.breakable == 1) {
					if (map[nxt_pos.y][nxt_pos.x] == 0 && visit[0][nxt_pos.y][nxt_pos.x] == 0) {
						push(nxt_pos);
						visit[0][nxt_pos.y][nxt_pos.x] = 1; // non-break visit

					}
					else if (map[nxt_pos.y][nxt_pos.x] == 1 && visit[0][nxt_pos.y][nxt_pos.x] == 0 && nxt_pos.breakable == 1) {
						nxt_pos.breakable = 0;
						push(nxt_pos);
						visit[0][nxt_pos.y][nxt_pos.x] = 1; // breaking time!

					}
				}
			}
		}
	}
	printf("-1");
}


int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();

	return 0;
}