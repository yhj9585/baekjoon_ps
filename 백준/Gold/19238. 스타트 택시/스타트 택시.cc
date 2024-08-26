#pragma warning (disable:4996)

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N; int M;

int sfuel = 0;
int nowY; int nowX;

int map[21][21] = { 0, };
int chk[21][21] = { 0, };

int arrival[405][2] = { 0,};

typedef struct node {
	int y;
	int x;
	int len;

	node(int y, int x, int l) : y(y), x(x), len(l) {}
}node;

class cmp {
public : bool operator()(node& a, node& b) const {
		if (a.y != b.y) {
			return a.y > b.y;
		}
		return a.x > b.x;
	}
};

queue<node> que;
priority_queue<node, vector<node>, cmp> pque;

int mover[4][2] = {
	{-1, 0},
	{ 0,-1},
	{ 0, 1},
	{ 1, 0 }
};

int check(node nxtpos) {
	if (nxtpos.y >= N || nxtpos.x >= N || nxtpos.y < 0 || nxtpos.x < 0) {
		return 0;
	}

	if (map[nxtpos.y][nxtpos.x] == 1) {
		return 0;
	}

	if (chk[nxtpos.y][nxtpos.x] != 0) {
		return 0;
	}

	if (map[nxtpos.y][nxtpos.x] == 0) {
		return 1;
	}

	return 2;
}

void simul() {

	int nowM = M;
	int nowF = sfuel;

	bool pt = false;

	int nowpassenger = 0;
	int toY = 0;
	int toX = 0;
	int end = 0;

	node newnode(nowY, nowX, 0);
	que.push(newnode);

	while (nowF != 0) {
		end = 0;
		memset(chk, 0, sizeof chk);
		auto tempos = que.front();
		chk[tempos.y][tempos.x] = 1;

		if (pt == false) {
			if (map[tempos.y][tempos.x] > 1) {
				nowpassenger = map[tempos.y][tempos.x];
				map[tempos.y][tempos.x] = 0;

				toY = arrival[nowpassenger][0];
				toX = arrival[nowpassenger][1];

				pt = true;
			}
		}

		// PT 0
		if (pt == false) {
			while (que.size() != 0) {
				auto nowpos = que.front();
				que.pop();

				if (pque.size() != 0) {
					if (nowpos.len >= pque.top().len) {
						break;
					}
				}

				for (int i = 0; i < 4; i++) {
					node nxtpos(nowpos.y + mover[i][0], nowpos.x + mover[i][1], nowpos.len + 1);

					if (check(nxtpos) == 1) {
						if (nxtpos.len == nowF) {
							continue;
						}

						que.push(nxtpos);
						chk[nxtpos.y][nxtpos.x] = 1;
					}
					else if (check(nxtpos) == 2) {
						pque.push(nxtpos);
						continue;
					}
					else {
						continue;
					}
				}
				if (end == 1) {
					break;
				}
			}
			

			if (pque.size() != 0) {
				auto tempos = pque.top();
				nowpassenger = map[tempos.y][tempos.x];

				que = queue<node>();
				toY = arrival[nowpassenger][0];
				toX = arrival[nowpassenger][1];

				map[tempos.y][tempos.x] = 0;

				nowF -= tempos.len;

				tempos.len = 0;

				que.push(tempos);

				pque = priority_queue<node, vector<node>, cmp>();

				end = 1;
				pt = true;
			}
			else {
				break;
			}

		}
		// PT 1

		else {
			while (que.size() != 0) {
				auto nowpos = que.front();
				que.pop();

				for (int i = 0; i < 4; i++) {
					node nxtpos(nowpos.y + mover[i][0], nowpos.x + mover[i][1], nowpos.len + 1);

					if (check(nxtpos) != 0) {
						if (nxtpos.y == toY && nxtpos.x == toX) {
							que = queue<node>();

							nowM--;
							nowF += nxtpos.len;
														
							if (nowM == 0) {
								printf("%d\n", nowF);
								return;
							}

							nxtpos.len = 0;
							que.push(nxtpos);

							end = 1;

							pt = false;

							break;
						}
						else {
							if (nxtpos.len == nowF) {
								continue;
							}
							que.push(nxtpos);
							chk[nxtpos.y][nxtpos.x] = 1;
						}
					}
					else {
						continue;
					}
				}

				if (end == 1) {
					break;
				}
			}
			if (end == 0) {
				break;
			}
		}
	}

	printf("-1\n");
	return;
}


int main() {
	scanf("%d %d %d", &N, &M, &sfuel);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int tempy; int tempx;
	scanf("%d %d", &nowY, &nowX);
	nowY--;
	nowX--;
	
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &tempy, &tempx);

		map[tempy-1][tempx-1] = i + 2;

		scanf("%d %d", &arrival[i + 2][0], &arrival[i + 2][1]);
		arrival[i + 2][0]--;
		arrival[i + 2][1]--;

	}


	simul();


	return 0;
}