#include <stdio.h>
#pragma warning(disable:4996)

int R, C;
int A, B;

char map[101][101];


int main() {

	scanf("%d %d", &R, &C);
	getchar();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &map[i][j]);
			map[i][2*C - j - 1] = map[i][j];
			map[2*R - i - 1][j] = map[i][j];
			map[2*R - i - 1][2*C - j - 1] = map[i][j];
		}
		getchar();
	}

	scanf("%d %d", &A, &B);

	if (map[A-1][B-1] == '.') {
		map[A-1][B-1] = '#';
	}
	else {
		map[A-1][B-1] = '.';
	}

	for (int i = 0; i < 2*R; i++) {
		for (int j = 0; j < 2 * C; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}


	return 0;
}