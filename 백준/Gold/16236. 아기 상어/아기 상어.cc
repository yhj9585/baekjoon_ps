#include <stdio.h>
#pragma warning(disable:4996) 

int N;
int map[22][22];
int visit[22][22];

struct pos {
	int x;
	int y;
	int depth;
};

pos move[5] = {
	{ 0, -1, 0},
	{ 0,  1, 0},
	{-1,  0, 0},
	{ 1,  0, 0}
};

pos queue[500];
int st, ed;

void push(pos npos) {
	queue[ed++] = npos;
	return;
}

pos pop() {
	return queue[st++];
}

int size() {
	return ed - st;
}

int compare(pos newfood, pos prefood) {
	if (newfood.depth > prefood.depth) {
		return -1;
	}
	if (newfood.y < prefood.y) {
		return 1;
	}
	else if (newfood.y == prefood.y) {
		if (newfood.x < prefood.x) {
			return 1;
		}
	}
	return 0;

}

int test(pos nxtpos, int visitN, int shark) {

	// 
	if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x < 0 || nxtpos.x >= N) {
		return -1;
	}


	// Eatable TEST //
	if (visit[nxtpos.y][nxtpos.x] != visitN) {
		if (map[nxtpos.y][nxtpos.x] == 0) {
			return 0;
		}
		if (map[nxtpos.y][nxtpos.x] < shark) {
			return 1;
		}
		else if (map[nxtpos.y][nxtpos.x] == shark) {
			return 0;
		}
	}
	return -1;
}

void eat() {
	int shark = 2;  // 상어의 크기
	int eatN = 0;   // 현재 크기에서 먹은 음식의 갯수
	int visitN = 1; // N번째로 갈 ... 

	pos npos;
	pos nxtpos;

	int firfood = 1; // food를 하나도 못 찾은 상태
	pos food;		 // 가능성이 가장 높은 음식

	int farchk = 0;  // 멀 경우 skip를 위해
	int Fulltime = 0;// 전체 걸린 시간

	while (1) {
		while (size() != 0) {
			npos = pop();

			for (int i = 0; i < 4; i++) {
				nxtpos.x = npos.x + move[i].x;
				nxtpos.y = npos.y + move[i].y;
				nxtpos.depth = npos.depth + 1;

				if (test(nxtpos, visitN, shark) == 1) { // shark is bigger
					visit[nxtpos.y][nxtpos.x] = visitN;
					if (firfood == 1) {
						food = nxtpos;
						firfood = 0;
					}
					else {
						if (compare(nxtpos, food) == 1) { // eatable
							food = nxtpos;
						}
						else if (compare(nxtpos, food) == -1) {
							// far //
							farchk = 1;
							break;
						}
					}
				}
				else if (test(nxtpos, visitN, shark) == 0) { // shark is passing
					push(nxtpos);
					visit[nxtpos.y][nxtpos.x] = visitN;
				}
			}
			if (farchk == 1) {
				farchk = 0;
				break;
			}
		}
		if (firfood == 0) {
			Fulltime += food.depth;
			map[food.y][food.x] = 0;

			// RESET //
			st = 0;
			ed = 0;

			eatN++;
			if (eatN == shark) {
				shark++;
				eatN = 0;
			}
			firfood = 1;
			visitN++;

			npos.y = food.y;
			npos.x = food.x;
			npos.depth = 0;

			push(npos);
			visit[npos.y][npos.x] = visitN;
		}
		else {
			break;
		}
	}

	printf("%d\n", Fulltime);
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				pos firpos = { j, i, 0 };
				push(firpos);
				map[i][j] = 0;
				visit[i][j] = 1;
			}
		}
	}

	eat();

	return 0;
}