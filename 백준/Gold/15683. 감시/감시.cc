#pragma warning (disable:4996)

#include <iostream>
#include <cstring>


using namespace std;

int N;
int M;

// ROUNDABLE N
int cctvR[6] = { 0,4,2,4,4,1 };

int map[10][10] = { 0, };

int chk[10][10] = { 0, };

int cctv[10][4] = { 0, };

int movep[4][2] = {
	{-1, 0}, // UP
	{ 0, 1}, // RIGHT
	{ 1, 0}, // DOWN
	{ 0,-1}  // LEFT
};

int smallest = 99999;
int cctvN = 0;

void gotoend(int y, int x, int dst) {
	int nowy = y;
	int nowx = x;

	while (nowy >= 0 && nowx >= 0 && nowy < N && nowx < M) {
		if (chk[nowy][nowx] == 6) {
			break;
		}
		
		chk[nowy][nowx] = 1;

		nowy += movep[dst][0];
		nowx += movep[dst][1];
	}

	return;
}


void endtest() {
	memcpy(chk, map, sizeof map);

	int nowy; int nowx;

	for (int i = 0; i < cctvN; i++) {
		nowy = cctv[i][0];
		nowx = cctv[i][1];

		switch (cctv[i][2]) {
		case 1:
			gotoend(nowy, nowx, cctv[i][3]);
			break;
		case 2:
			gotoend(nowy, nowx, cctv[i][3]);
			gotoend(nowy, nowx, cctv[i][3] + 2);
			break;
		case 3:
			gotoend(nowy, nowx, cctv[i][3]);
			if (cctv[i][3] == 3) {
				gotoend(nowy, nowx, 0);
			}
			else {
				gotoend(nowy, nowx, cctv[i][3] + 1);
			}
			break;
		case 4:
			for (int j = 0; j < 4; j++) {
				if (j == cctv[i][3]) {
					continue;
				}
				gotoend(nowy, nowx, j);
			}
			break;
		case 5:
			for (int j = 0; j < 4; j++) {
				gotoend(nowy, nowx, j);
			}
			break;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (chk[i][j] == 0) {
				cnt++;
			}
		}
	}

	if (cnt < smallest) {
		smallest = cnt;
	}

	return;

}

void simul(int nTh) {
	if (nTh == cctvN) {
		endtest();
		return;
	}

	for (int i = 0; i < cctvR[cctv[nTh][2]]; i++) {
		cctv[nTh][3] = i;
		simul(nTh + 1);
	}

	return;
}

int lefttochk;

int main() {

	scanf("%d %d", &N, &M);

	lefttochk = N * M;

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp);
			if (temp > 0 && temp < 6) {
				cctv[cctvN][0] = i;
				cctv[cctvN][1] = j;
				cctv[cctvN][2] = temp;

				cctvN++;
				lefttochk--;
			}
			else {
				map[i][j] = temp;

				if (temp == 6) {
					lefttochk--;
				}
			}
		}
	}

	simul(0);

	printf("%d\n", smallest);

	return 0;
}