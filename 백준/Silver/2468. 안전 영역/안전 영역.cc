#include <stdio.h>
#pragma warning(disable: 4996)

int N;
int map[101][101];
int chk[101][101];

struct pos {
	int x, y;
};

pos move[4]{
	{-1,  0},
	{ 1,  0},
	{ 0, -1},
	{ 0,  1}
};

// queue //
pos queue[100005];
int st, ed;

void push(pos n_pos) {
	queue[ed++] = n_pos;
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

pos nxt(pos n_pos, int i) {
	pos nxt_pos;
	nxt_pos.x = n_pos.x + move[i].x;
	nxt_pos.y = n_pos.y + move[i].y;

	return nxt_pos;
}

int inside(pos n, int height) {
	if (n.x >= 0 && n.y >= 0 && n.x < N && n.y < N) {
		if (map[n.y][n.x] > height&& chk[n.y][n.x] != height) {
			return 1;
		}
	}
	return 0;
	
}

void bfs(int height) {

	pos n_pos;
	pos nxt_pos;
	while (size() != 0) {
		n_pos = pop();

		for (int i = 0; i < 4; i++) {
			nxt_pos = nxt(n_pos, i);

			if (inside(nxt_pos, height)) {
				push(nxt_pos);
				chk[nxt_pos.y][nxt_pos.x] = height;
			}

		}

	}




}

void safty(int height) {
	
	int island = 0;
	int larger = 0;

	for (int h = 1; h < height; h++) {


		island = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				
				if (map[i][j] > h&& chk[i][j] != h) {
					island++;
					push({ j, i });
					bfs(h);
				}


			}
		}
	
		if (island > larger) {
			larger = island;
		}

		reset();
	}

	printf("%d\n", larger);


}


int main() {
	scanf("%d", &N);

	int large = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] > large) {
				large = map[i][j];
			}
		}
	}


	if (large == 1) {
		printf("1\n");
		return 0;
	}

	safty(large);


	return 0;
}