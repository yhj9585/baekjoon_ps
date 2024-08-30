#include <stdio.h>
#pragma warning(disable:4996)

int L, W;
int map[51][51];
int visit[51][51];
int ground = 0;

struct pos {
	int x, y;
	int far;
};

pos move[4] = {
	{-1,  0, 0},
	{ 1,  0, 0},
	{ 0, -1, 0},
	{ 0,  1, 0}
};

// queue //
pos queue[3000] = { 0, };
int st, ed;

void push(pos n) {
	queue[ed++] = n;
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

}

pos nxt(pos n, int i) {
	pos nxt_pos;
	nxt_pos.x = n.x + move[i].x;
	nxt_pos.y = n.y + move[i].y;
	nxt_pos.far = n.far + 1;
	return nxt_pos;
}

int chk(pos n) {
	if (n.x >= 0 && n.y >= 0) {
		if (n.x < W && n.y < L) {
			return 1;
		}
	}
	return 0;

}


// bfs //
int bfs(int a) {
	int far = 0;

	while (size() != 0) {
		pos n_pos = pop();
		pos nxt_pos;

		for (int i = 0; i < 4; i++) {
			nxt_pos = nxt(n_pos, i);

			if (chk(nxt_pos)) {
				if (visit[nxt_pos.y][nxt_pos.x] != a && map[nxt_pos.y][nxt_pos.x] == 1) {

					push(nxt_pos);
					visit[nxt_pos.y][nxt_pos.x] = a;
					if (nxt_pos.far > far) {
						far = nxt_pos.far;
					}
				}
			}
		}
	}

	reset();
	return far;

}

int large;

void find() {
	int ths;
	int point = 0;

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {

			if (map[i][j] == 1) {
				point++;
				pos npos = { j, i, 0 };
				visit[i][j] = point;
				push(npos);
				ths = bfs(point);

				if (ths > large) {
					large = ths;
				}
			}

		}
	}

	printf("%d", large);

}


int main() {
	scanf("%d %d", &L, &W);

	getchar();

	char land;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%c", &land);

			if (land == 'W') {
				map[i][j] = 0;
			}
			else if (land == 'L') {
				map[i][j] = 1;
				ground++;
			}
		}
		getchar();
	}

	find();



}
