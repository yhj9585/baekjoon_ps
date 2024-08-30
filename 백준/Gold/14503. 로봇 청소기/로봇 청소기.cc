#include <stdio.h>

int N, M;
int map[51][51];
int chk[51][51];

struct pos {
	int x, y;
	int dir;
};

pos start;

pos move[4] = {
	{ 0, -1},
	{ 1,  0},
	{ 0,  1},
	{-1,  0}
};

// dir 0 = n
// dir 1 = e
// dir 2 = s
// dir 3 = w

pos nxt_dir(pos n) {
	pos nxt = n;
	if (n.dir == 0) {
		nxt.dir = 3;
	}
	else {
		nxt.dir = n.dir - 1;
	}
	return nxt;
}

pos nxt_way(pos n) {
	pos nxt = n;
	nxt.x = n.x + move[n.dir].x;
	nxt.y = n.y + move[n.dir].y;

	return nxt;

}

pos backward(pos n) {
	pos nxt = n;
	nxt.x = n.x - move[n.dir].x;
	nxt.y = n.y - move[n.dir].y;
	return nxt;
}

int check(pos n) {
	for (int i = 0; i < 4; i++) {
		if (map[n.y + move[i].y][n.x + move[i].x] == 0) {
			return 1;
		}
	}
	return 0;
}

int way = 1;
void test() {

	pos ths = start;
	map[ths.y][ths.x] = 2;
	pos tes;
	int problem = 0;
	while (true) {

		problem = 0;
		for (int i = 0; i < 4; i++) {
			ths = nxt_dir(ths);
			tes = nxt_way(ths);
			if (map[tes.y][tes.x] == 0) {
				ths = tes;
				way++;
				map[tes.y][tes.x] = 2;
				break;
			}
			if (i == 3) {
				problem = 1;
			}

		}
		
		if (problem == 1) {
			ths = backward(ths);
			if (map[ths.y][ths.x] == 1) {
				break;
			}
		}
	}
	printf("%d\n", way);
}


int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &start.y, &start.x, &start.dir);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	test();

	return 0;
}
