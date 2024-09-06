#pragma warning (disable:4996)

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N; int M; int D;

int basemap[20][20] = { 0, };
int map[20][20];
int chk[20][20] = { 0, };

int arrow[20] = { 0, };

int benemy[400][3] = { 0, };
int enemy[400][3] = {0,};
int enemyN = 0;

int best = 0;

int mover[4][2] = {
	{ 0, -1},
	{-1,  0},
	{ 1,  0},
	{ 0,  1}
};

typedef struct node {
	int y;
	int x;
	int depth;
	node(int y, int x, int d) : y(y), x(x), depth(d) {}
}node;

queue<node> que;

int check(node nxtpos) {
	if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= M || nxtpos.x < 0) {
		return 0;
	}
	if (chk[nxtpos.y][nxtpos.x] != 0) {
		return 0;
	}
	if (nxtpos.depth > D) {
		return 0;
	}
	if (map[nxtpos.y][nxtpos.x] != 0) {
		return 2;
	}
	return 1;
}

int bfs() {
	while (!que.empty()) {
		auto nowpos = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			node nxtpos(nowpos.y + mover[i][0], nowpos.x + mover[i][1], nowpos.depth + 1);

			if (check(nxtpos) == 1) {
				chk[nxtpos.y][nxtpos.x] = 1;
				que.push(nxtpos);
			}
			if (check(nxtpos) == 2) {
				//enemy[map[nxtpos.y][nxtpos.x]][0] = 0;
				return map[nxtpos.y][nxtpos.x];
			}


		}
	}

	return -1;
}

void simul() {
	int eliminated = 0;
	int shoot = 0;

	int shot[4] = { 0, };

	memcpy(map, basemap, sizeof basemap);
	memcpy(enemy, benemy, sizeof benemy);

	while (eliminated != enemyN) {
		// Turn
		for (int a = 0; a < 3; a++) {
			memset(chk, 0, sizeof chk);
			que = queue<node>();

			que.push(node(N, arrow[a], 0));

			shot[a] = bfs();
		}

		for (int a = 0; a < 3; a++) {
			if (shot[a] != -1) {
				if (enemy[shot[a]][0] != 0) {
					shoot++;
					eliminated++;
					map[enemy[shot[a]][1]][enemy[shot[a]][2]] = 0;
					enemy[shot[a]][0] = 0;
				}
			}
		}

		if (eliminated == enemyN) {
			break;
		}

		for (int i = 0; i < M; i++) {
			if (map[N - 1][i] != 0) {
				eliminated++;
				enemy[map[N - 1][i]][0] = 0;
			}
		}

		if (eliminated == enemyN) {
			break;
		}

		memset(map, 0, sizeof map);
		for (int i = 1; i <= enemyN; i++) {
			if (enemy[i][0] != 0) {
				enemy[i][1]++;

				map[enemy[i][1]][enemy[i][2]] = i;
			}
		}
	}

	if (best < shoot) {
		best = shoot;
	}

	return;
}

void force(int depth, int bef) {
	if (depth == 3) {
		simul();
	}

	for (int i = bef + 1; i < M; i++) {
		arrow[depth] = i;
		force(depth + 1, i);
	}

}

int main() {
	scanf("%d %d %d", &N, &M, &D);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &basemap[i][j]);
			if (basemap[i][j] == 1) {
				enemyN++;
				benemy[enemyN][0] = 1;
				benemy[enemyN][1] = i;
				benemy[enemyN][2] = j;
				basemap[i][j] = enemyN;

			}

		}
	}

	force(0, -1);
	printf("%d\n", best);

	return 0;
}