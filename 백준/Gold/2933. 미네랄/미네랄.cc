#pragma warning (disable:4996)
#include <stdio.h>

int R; int C;
char map[101][101] = { 0, };
int chk[101][101] = { 0, };

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

pos queue[10001] = { 0, };
int st; int ed;
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

int numofMineal = 0;
int time = 0;
int lowestmap[101] = { 0, };

void pri() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	/*
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d", chk[i][j]);
		}
		printf("\n");
	}
	*/
	//printf("\n");
	return;
}

int check(pos nowpos) {
	if (nowpos.y >= R || nowpos.y < 0 || nowpos.x >= C || nowpos.x < 0) {
		return 0;
	}
	else if (map[nowpos.y][nowpos.x] == '.') {
		return 0;
	}
	else if (chk[nowpos.y][nowpos.x] == time) {
		return 0;
	}
	else {
		return 1;
	}
}

int bfs() {
	pos nowpos = { 0, };
	pos nxtpos = { 0, };
	int dropable = 1;
	while (size() != 0) {
		nowpos = pop();
		for (int i = 0; i < 4; i++) {
			nxtpos.y = nowpos.y + move[i][0];
			nxtpos.x = nowpos.x + move[i][1];
			if (check(nxtpos) == 1) {
				chk[nxtpos.y][nxtpos.x] = time;
				if (lowestmap[nxtpos.x] < nxtpos.y || lowestmap[nxtpos.x] == 101) {
					lowestmap[nxtpos.x] = nxtpos.y;
				}
				if (lowestmap[nxtpos.x] == R - 1) {
					dropable = 0;
				}
				push(nxtpos);
			}
		}
	}
	//pri();
	if (dropable == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void drop() {
	int smallestGap = 101;
	for (int i = 0; i < C; i++) {
		for (int j = 1; lowestmap[i] + j < R; j++) {
			if (lowestmap[i] == 101) {
				break;
			}
			if (map[lowestmap[i] + j][i] == 'x') {
				if (smallestGap > j - 1) {
					smallestGap = j - 1;
				}
				break;
			}
			else if (lowestmap[i] + j == R-1) {
				if (smallestGap > j) {
					smallestGap = j;
				}
				break;
			}

			if (j > smallestGap) {
				break;
			}
		}
		if (smallestGap == 1) {
			break;
		}
	}

	for (int i = 0; i < st; i++) {
		map[queue[i].y][queue[i].x] = '.';
	}
	for (int i = 0; i < st; i++) {
		map[queue[i].y + smallestGap][queue[i].x] = 'x';
	}
	return;
}

void simul(int startY, int startX) {
	pos nowpos;
	pos nxtpos;
	nowpos.y = startY;
	nowpos.x = startX;
	int numofbfs = 0;
	
	for (int i = 0; i < 4; i++) {
		nxtpos.y = nowpos.y + move[i][0];
		nxtpos.x = nowpos.x + move[i][1];
		if (check(nxtpos)) {
			numofbfs++;
			st = 0; ed = 0;
			push(nxtpos);
			chk[nxtpos.y][nxtpos.x] = time;
			for (int j = 0; j < C; j++) {
				lowestmap[j] = 101;
			}
			lowestmap[nxtpos.x] = nxtpos.y;
			if (bfs() == 1) {
				drop();
				//pri();
				return;
			}
			if (numofbfs == 2) {
				return;
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d", &R, &C);

	getchar();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1c", &map[i][j]);
			if (map[i][j] == 'x') {
				numofMineal++;
			}
		}
		getchar();
	}

	int N = 0;
	int nowdir = 1;
	int nowHeight = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nowHeight);
		nowHeight = R-nowHeight;

		if (i % 2 == 0) { // 홀수
			for (int j = 0; j < C; j++) {
				if (map[nowHeight][j] == 'x') {
					map[nowHeight][j] = '.';
					numofMineal--;
					time++;
					//pri();
					simul(nowHeight, j);
					break;
				}
			}
		}
		else {			// 짝수
			for (int j = C - 1; j >= 0; j--) {
				if (map[nowHeight][j] == 'x') {
					map[nowHeight][j] = '.';
					numofMineal--;
					time++;
					//pri();
					simul(nowHeight, j);
					break;
				}
			}
		}
	}
	pri();

	return 0;
}