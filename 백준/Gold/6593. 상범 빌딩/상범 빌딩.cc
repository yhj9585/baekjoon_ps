#include <stdio.h>
#pragma warning(disable: 4996)

int L, R, C;
int map[31][31][31];
int chk[31][31][31];

struct pos {
	int x, y, z;
	int time;
};

pos move[6]{
	{-1,  0,  0, 0},
	{ 1,  0,  0, 0},
	{ 0, -1,  0, 0},
	{ 0,  1,  0, 0},
	{ 0,  0, -1, 0},
	{ 0,  0,  1, 0}
};

// queue //
pos queue[100000];
int ed, st;

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
	return;
}

pos nxt(pos n, int i) {
	pos nxt_pos;
	nxt_pos.x = n.x + move[i].x;
	nxt_pos.y = n.y + move[i].y;
	nxt_pos.z = n.z + move[i].z;
	nxt_pos.time = n.time + 1;
	return nxt_pos;
}

int check(pos nxt) {
	if (nxt.x >= 0 && nxt.y >= 0 && nxt.z >= 0 && nxt.x < C && nxt.y < R && nxt.z < L) {
		if (map[nxt.z][nxt.y][nxt.x] == 0 || map[nxt.z][nxt.y][nxt.x] == 2) {
			if (chk[nxt.z][nxt.y][nxt.x] == 0) {
				return 1;
			}
		}
	}
	return 0;
}

void bfs() {



	pos n_pos;
	pos nxt_pos;
	while (size() != 0) {
		n_pos = pop();

		/*
		if (n_pos.x == 3 && n_pos.y == 3, n_pos.z == 1) {
			printf("asdf");
		}
		*/

		if (map[n_pos.z][n_pos.y][n_pos.x] == 2) {
			printf("Escaped in %d minute(s).\n", n_pos.time);
			return;
		}

		for (int i = 0; i < 6; i++) {
			nxt_pos = nxt(n_pos, i);

			if (check(nxt_pos)) {
				push(nxt_pos);
				chk[nxt_pos.z][nxt_pos.y][nxt_pos.x] = 1;
			}

		}

	}
	printf("Trapped!\n");


}


int main() {

	while (true) {

		scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0) {
			break;
		}

		char a;
		getchar();
		for (int i = 0; i < L; i++) {

			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					scanf("%c", &a);
					if (a == '.') {
						map[i][j][k] = 0;
						chk[i][j][k] = 0;
					}
					else if (a == '#') {
						map[i][j][k] = 1;
						chk[i][j][k] = 0;
					}
					else if (a == 'S') {
						push({ k, j, i, 0 });
						chk[i][j][k] = 1;
					}
					else {
						map[i][j][k] = 2;
						chk[i][j][k] = 0;
					}

				}
				getchar();
			}
			if (i != L - 1) {
				getchar();
			}

		}

		bfs();
		reset();

	}

}