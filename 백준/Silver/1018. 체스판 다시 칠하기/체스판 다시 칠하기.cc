#include <stdio.h>
#pragma warning(disable:4996)

int N, M;
int map[55][55];




int chk(int n, int stx, int sty) {
	int dif = 0;

	for (int i = sty; i < sty+8; i++) {
		for (int j = stx; j < stx+8; j++) {
			
			if (map[i][j] == n) {
				if (i % 2 == 0 && j % 2 == 1) {
					dif++;
				}
				else if (i % 2 == 1 && j % 2 == 0) {
					dif++;
				}
			}
			else {
				if (i % 2 == 0 && j % 2 == 0) {
					dif++;
				}
				else if (i % 2 == 1 && j % 2 == 1) {
					dif++;
				}
			}

		}
	}

	return dif;
}

void test() {
	int small = M*N;
	int ans1, ans2;

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			ans1 = chk(1, j, i);
			ans2 = chk(0, j, i);

			if (ans1 > ans2) {
				if (small > ans2) {
					small = ans2;
				}
			}
			else {
				if (small > ans1) {
					small = ans1;
				}
			}
		}
	}

	printf("%d\n", small);


}

int main() {
	scanf("%d %d", &N, &M);

	getchar();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			scanf("%1c", &c);

			if (c == 'W') {
				map[i][j] = 0;
			}
			else if (c == 'B') {
				map[i][j] = 1;
			}
		}
		getchar();
	}


	test();

}