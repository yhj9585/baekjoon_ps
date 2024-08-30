#pragma warning (disable:4996)

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N; int M;

int map[210][210] = { 0, };

int ghostSee[4][210][210] = { 0, };

int movep[5][2] = {
	{ 0, 1},
	{ 1, 0},
	{ 0,-1},
	{-1, 0},
	{ 0, 0}
};

typedef struct ghost {
	int y; 
	int x;
	int to;
	ghost(int y, int x, int t) : y(y), x(x), to(t) {}
}ghost;

typedef struct node {
	int y;
	int x;
	int depth;
	node(int y, int x, int d) : y(y), x(x), depth(d) {}
}node;

vector<ghost> ghostlist;
queue<node> que;

int endy; int endx;
int nowy; int nowx;

int check(node nxtpos, int nxtime) {
	if (nxtpos.y < 0 || nxtpos.y >= N || nxtpos.x < 0 || nxtpos.x >= M) {
		return 0;
	}
	else if (map[nxtpos.y][nxtpos.x] != 0) {
		return 0;
	}
	else if (ghostSee[nxtime][nxtpos.y][nxtpos.x] != 0) {
		return 0;
	}
	else {
		return 1;
	}
}

void simul() {
	int nxtime = 0;

	que.push(node(nowy, nowx, 0));
	while (que.size() != 0) {
		auto nowpos = que.front();
		que.pop();

		for (int i = 0; i < 5; i++) {
			node nxtpos(nowpos.y + movep[i][0], nowpos.x + movep[i][1], nowpos.depth + 1);

			nxtime = nxtpos.depth % 4;
			if (check(nxtpos, nxtime)) {
				if (endy == nxtpos.y && endx == nxtpos.x) {
					printf("%d\n", nxtpos.depth);
					return;
				}

				ghostSee[nxtime][nxtpos.y][nxtpos.x] = 7;
				que.push(nxtpos);
			}
			else {
				continue;
			}

		}
	}

	printf("GG\n");
	return;
}

void toEnd(int y, int x, int to, int time) {
	int nowy = y;
	int nowx = x;

	nowy += movep[to][0];
	nowx += movep[to][1];
	while (nowy < N && nowx < M && nowy >= 0 && nowx >= 0) {
		if (ghostSee[time][nowy][nowx] == 1 || ghostSee[time][nowy][nowx] == 2) {
			break;
		}
		
		ghostSee[time][nowy][nowx] = 5;

		nowy += movep[to][0];
		nowx += movep[to][1];
	}
	return;
}

void beftest() {
	int gy; int gx; int gto;

	for (int i = 0; i < 4; i++) {
		memcpy(ghostSee[i], map, sizeof map);
		for (int g = 0; g < ghostlist.size(); g++) {
			gy  = ghostlist[g].y;
			gx  = ghostlist[g].x;
			gto = ghostlist[g].to;

			toEnd(gy, gx, gto, i);

			ghostlist[g].to += 1;
			if (ghostlist[g].to > 3) {
				ghostlist[g].to = 0;
			}
		}
	}


}

int main() {
	scanf("%d %d", &N, &M);
	
	scanf("%d %d %d %d", &nowy, &nowx, &endy, &endx);

	nowy--;
	nowx--;
	endy--;
	endx--;

	char temp;
	getchar();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1c", &temp);
			if (temp == '.') {
				map[i][j] = 0;
			}
			else if (temp == '#') {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 2;
				ghostlist.push_back(ghost(i, j, temp-48));
			}
		}
		getchar();
	}

	beftest();
	simul();
	

	return 0;
}