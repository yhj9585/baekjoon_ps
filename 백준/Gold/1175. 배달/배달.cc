#include <stdio.h>
#pragma warning(disable:4996)

int N = 0; int M = 0;
int map[51][51] = { 0, };
int chk[6][4][51][51] = { 0, };

int giftmap[51][51] = { 0, };

int move[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

typedef struct pos {
	int dir;
	int y;
	int x;
	int depth;
	int gift;
}pos;

pos queue[50000] = { 0, };
int st = 0; int ed = 0;
void push(pos nxtpos) {
	queue[st++] = nxtpos;
	return;
}
pos pop() {
	return queue[ed++];
}
int size() {
	return st - ed;
}

int check(pos nxtpos) {
	if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= M || nxtpos.x < 0) {
		return 0;
	}
	if (chk[nxtpos.gift][nxtpos.dir][nxtpos.y][nxtpos.x] != 0) {
		return 0;
	}
	if (map[nxtpos.y][nxtpos.x] == 1) {
		return 0;
	}
	if (map[nxtpos.y][nxtpos.x] == 3) {
		if (nxtpos.gift == 3) {
			return 1;
		}
		else if (nxtpos.gift == 4) {
			return 5;
		}
		else {
			return 3;
		}
	}
	else if (map[nxtpos.y][nxtpos.x] == 4) {
		if (nxtpos.gift == 4) {
			return 1;
		}
		else if (nxtpos.gift == 3) {
			return 5;
		}
		else {
			return 4;
		}
	}
	return 1;
}

void simul() {
	pos nowpos;
	pos nxtpos;
	int test = 0;

	while (size() != 0) {
		nowpos = pop();
		//printf("%d %d gift %d depth %d dir %d\n", nowpos.y, nowpos.x, nowpos.gift, nowpos.depth, nowpos.dir);

		for (int i = 0; i < 4; i++) {
			if (nowpos.dir == i) {
				continue;
			}
			nxtpos.y = nowpos.y + move[i][0];
			nxtpos.x = nowpos.x + move[i][1];
			nxtpos.dir = i;
			nxtpos.depth = nowpos.depth + 1;
			nxtpos.gift = nowpos.gift;

			test = check(nxtpos);
			if (test == 1) { // nothing
				chk[nxtpos.gift][i][nxtpos.y][nxtpos.x] = 1;
				//printf("-> %d %d dir %d depth %d gift %d \n", nxtpos.y, nxtpos.x, nxtpos.dir, nxtpos.depth, nxtpos.gift);
				push(nxtpos);
			}
			else if (test == 3) { // C //
				chk[nxtpos.gift][i][nxtpos.y][nxtpos.x] = 1;
				nxtpos.gift = 3;
				chk[nxtpos.gift][i][nxtpos.y][nxtpos.x] = 1;
				//printf("-> %d %d dir %d depth %d gift %d \n", nxtpos.y, nxtpos.x, nxtpos.dir, nxtpos.depth, nxtpos.gift);
				push(nxtpos);
			}
			else if (test == 4) { // C2 //
				chk[nxtpos.gift][i][nxtpos.y][nxtpos.x] = 1;
				nxtpos.gift = 4;
				chk[nxtpos.gift][i][nxtpos.y][nxtpos.x] = 1;
				//printf("-> %d %d dir %d depth %d gift %d \n", nxtpos.y, nxtpos.x, nxtpos.dir, nxtpos.depth, nxtpos.gift);
				push(nxtpos);
			}
			else if (test == 5) {
				printf("%d\n", nxtpos.depth - 1);
				return;
			}
			else {
				continue;
			}
		}
	}
	printf("-1\n");
	return;
}

int main() {
	scanf("%d %d", &N, &M);

	char tmp; pos nowpos = { 0, };
	nowpos.depth = 1;
	nowpos.dir = -1;
	nowpos.gift = 0;

	getchar();

	int giftN = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1c", &tmp);
			if (tmp == 'S') {
				nowpos.y = i;
				nowpos.x = j;
			}
			else if (tmp == 'C') {
				map[i][j] = 3+ (giftN++);

			}
			else if (tmp == '#') {
				map[i][j] = 1;
			}
		} 
		getchar();
	}

	for (int i = 0; i < 4; i++) {
		chk[0][i][nowpos.y][nowpos.x] = 1;
	}
	push(nowpos);
	simul();

	return 0;
}