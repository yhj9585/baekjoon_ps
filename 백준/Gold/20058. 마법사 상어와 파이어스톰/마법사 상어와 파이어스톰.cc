#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996) 

int N, Q;
int L;

int map[70][70];
int melt[70][70];

int moveX[4] = { -1, 1, 0, 0 };
int moveY[4] = { 0, 0, -1, 1 };

struct pos {
	int x, y;
};

pos queue[10000];
int visit[70][70];
int st, ed;

void push(pos n) {
	queue[ed++] = n;
	return;
}
pos pop() {
	return queue[st++];
}
int size() {
	return ed - st;
}

int check(pos nxt) {
	if (nxt.x >= 0 && nxt.y >= 0 && nxt.x < L && nxt.y < L) {
		if (map[nxt.y][nxt.x] > 0 && visit[nxt.y][nxt.x] == 0) {
			return 1;
		}
	}

	return 0;
}


int bfs() {

	int ices = 1;
	pos npos;
	pos nxt;
	while (size()!= 0) {
		npos = pop();

		for (int i = 0; i < 4; i++) {
			nxt.x = moveX[i] + npos.x;
			nxt.y = moveY[i] + npos.y;
			if (check(nxt)) {
				push(nxt);
				visit[nxt.y][nxt.x] = 1;
				ices++;
			}

		}
	}

	return ices;
}







void count() {

	int iceN = 0;	int iceL;
	int Large = 0;

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {

			if (map[i][j] > 0) {
				iceN += map[i][j];

				if (visit[i][j] == 0) {

					push({ j,i });
					visit[i][j] = 1;
					iceL = bfs();
					if (Large < iceL) {
						Large = iceL;
					}

				}
			}
		}
	}

	printf("%d\n", iceN);
	printf("%d\n", Large);

}
int tmp[70][70];

void fireStorm(int sep) {


	int leng = pow(2, sep);
	int a = pow(2, N - sep);

	for (int i = 0; i < leng; i++) {
		for (int j = 0; j < leng; j++) {

			for (int block = 0; block < pow(a, 2); block++) {
				int x = (block % a) * leng;
				int y = (block / a) * leng;

				tmp[i + y][j + x] = map[leng - 1 - j + y][i + x];

			}

		}
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}




void Melting(int time) {

	int x, y;
	int Less = 0;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			Less = 0;
			for (int m = 0; m < 4; m++) {
				x = j + moveX[m];
				y = i + moveY[m];
				if (x < 0 || x == L || y < 0 || y == L || map[y][x] == 0) {
					Less++;
				}
				if (Less >= 2) {
					melt[i][j] = time;
					break;
				}
			}


		}
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			if (melt[i][j] == time) {
				if (map[i][j] == 0) {
					continue;
				}
				map[i][j]--;
			}
		}
	}
}




int main() {

	scanf("%d %d", &N, &Q);
	L = pow(2, N);
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int sep;
	for (int i = 0; i < Q; i++) {
		scanf("%d", &sep);
		fireStorm(sep);
		Melting(i+1);
	}

	count();



	return 0;
}