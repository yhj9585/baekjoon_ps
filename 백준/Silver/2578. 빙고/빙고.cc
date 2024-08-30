#include <stdio.h>

int main() {
	int pan[5][5];
	//입력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &pan[i][j]);
		}
	}

	//체크 밑 확인

	int line = 0;					//빙고 라인
	int number = 0;					//사회자의 말
	int check[5][5] = { 0, };		//체크하는 판
	int circle = 0;					//맞는거 체크
	int bingo = 0;

	//입력

	for (int a = 1; a <= 25; a++) {
		scanf("%d", &number);

		line = 0;

		//맞으면 동그라미
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (number == pan[i][j]) {
					check[i][j] = 1;
				}
			}
		}

		//가로 확인
		for (int x = 0; x < 5; x++) {
			circle = 0;
			for (int y = 0; y < 5; y++) {
				if (check[x][y] == 1) {
					circle++;
				}
			}
			if (circle == 5) {
				line += 1;

			}
		}

		//세로 확인
		for (int y = 0; y < 5; y++) {
			circle = 0;
			for (int x = 0; x < 5; x++) {
				if (check[x][y] == 1) {
					circle++;
				}
			}
			if (circle == 5) {
				line += 1;
			}
		}

		//대각선 확인
		circle = 0;
		for (int x = 0; x < 5; x++) {
			if (check[x][x] == 1) {
				circle++;
			}
			if (circle == 5) {
				line += 1;
			}
		}

		circle = 0;
		for (int x = 0; x < 5; x++) {
			if (check[x][4 - x] == 1) {
				circle++;
			}
			if (circle == 5) {
				line += 1;
			}
		}

		//3줄 빙고
		if (line >= 3 && bingo == 0) {
			bingo = a;
		}

	}
	printf("%d", bingo);
}