#include <stdio.h>
#pragma warning(disable : 4996) 

int N;
int base[25][25];
int map[6][25][25];
int check[6][25][25];

int ci[5];

// left  1
// right 2
// up    3
// down  4

struct pos {
	int x, y;
};

pos move[5] = {
	{  0,  0},
	{ -1,  0},	
	{  1,  0},
	{  0, -1},
	{  0,  1}
};

int chk(int ny, int nx, int dir) {
	if (dir == 1) {
		if (nx != 0) return 1;
	}
	else if (dir == 2) {
		if (nx != N - 1) return 1;
	}
	else if (dir == 3) {
		if (ny != 0) return 1;
	}
	else {
		if (ny != N - 1) return 1;
	}
	return 0;
}

void block(int y, int x, int dir, int level) {

	int nx = x;
	int ny = y;

	int nxtx;
	int nxty;

	int plus = 0;

	while (chk(ny, nx, dir)) {
		
		nxtx = nx + move[dir].x;
		nxty = ny + move[dir].y;


		if (map[level][nxty][nxtx] == 0) {
			map[level][nxty] [nxtx] = map[level][ny][nx];
			map[level][ny][nx] = 0;
		}
		else if (map[level][nxty][nxtx] == map[level][ny][nx] && plus == 0 && check[level][nxty][nxtx] == 0) {
			map[level][nxty][nxtx] *= 2;
			map[level][ny][nx] = 0;
			plus = 1;
			
		}
		else if (map[level][nxty][nxtx] != 0) {
			break;
		}

		nx = nxtx;
		ny = nxty;

	}
	if (plus == 1) {
		check[level][ny][nx] = 1;
	}

}

void pan(int dir, int level) {

	if (dir == 1) {
		for (int y = 0; y < N; y++) {
			for (int x = 1; x < N; x++) {
				block(y, x, dir, level);
			}
		}
	}
	else if (dir == 2) {
		for (int y = 0; y < N; y++) {
			for (int x = N - 2; x >= 0; x--) {
				block(y, x, dir, level);

			}
		}
	}
	else if (dir == 3) {
		for (int x = 0; x < N; x++) {
			for (int y = 1; y < N; y++) {
				block(y, x, dir, level);
			}
		}
	}
	else if (dir == 4) {
		for (int x = 0; x < N; x++) {
			for (int y = N - 2; y >= 0; y--) {
				block(y, x, dir, level);
			}
		}
	}

}

void reset(int lev) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[lev][i][j] = map[lev-1][i][j];
			check[lev][i][j] = 0;
		}
	}
}


int large;
void dfs(int level) {

	if (level == 5) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[5][i][j] > large) large = map[5][i][j];
			}
		}

		return;
	}

	for (int i = 1; i < 5; i++) {


		if (i == 3)
			printf("");
		if (i == 2) 
			printf("");

		reset(level+1);
		pan(i, level+1);
		ci[level] = i;

		// reset check

		dfs(level+1);
	}


}


int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[0][i][j]);
		}
	}

	dfs(0);
	
	/*
	int t = 1;
	while (true) {
		
		int r;

		reset(t);
		scanf("%d", &r);

		pan(r, t);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%5d", map[t][i][j]);
			}
			printf("\n");
		}
		t++;
	}
	*/
	printf("%d\n", large);


	return 0;
}