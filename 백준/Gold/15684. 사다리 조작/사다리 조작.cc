#include <stdio.h>

int N, M, H;
int ladderN;
int fin;
int ladder[31][11];

void dfs(int y, int cnt) {

	if (fin) {
		return;
	}

	if (ladderN == cnt) {
		bool possible = true;
		for (int i = 1; i <= N; i++) {

			int row = i;
			for (int j = 0; j < H; j++) {

				if (ladder[j][row])
					row++;
				else if (row > 1 && ladder[j][row - 1])
					row--;
			}

			if (i != row) {

				possible = 0;
				break;
			}
		}

		if (possible)
			fin = true;
		return;
	}

	for (int i = y; i < H; i++) {
		for (int j = 1; j < N; j++) {

			if (!ladder[i][j - 1] && !ladder[i][j] && !ladder[i][j + 1]) {
				ladder[i][j] = 1;
				dfs(i, cnt + 1);
				ladder[i][j] = 0;
			}
		}
	}
	return;
}


int main() {
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) {

		int x, y;
		scanf("%d %d", &y, &x);
		ladder[y - 1][x] = 1;
	}

	for (int i = 0; i <= 3; i++) {

		ladderN = i;
		dfs(0, 0);

		if (fin) {
			printf("%d\n", ladderN);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
