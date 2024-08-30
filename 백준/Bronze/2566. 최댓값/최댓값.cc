#include <stdio.h>

int main() {
	int pan[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &pan[i][j]);
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int cnt = 0;
			for (int x = 0; x < 9; x++) {
				for (int y = 0; y < 9; y++) {
					if (pan[i][j] < pan[x][y]) {
						cnt += 1;
						break;
					}
				}
			}
			if (cnt < 1) {
				printf("%d\n", pan[i][j]);
				printf("%d ", i + 1);
				printf("%d ", j + 1);
			}
		}
	}
}