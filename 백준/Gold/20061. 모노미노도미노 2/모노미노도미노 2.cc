#include <stdio.h>
#pragma warning(disable:4996)

int map[10][10];
// RED  [0]~[3]
// BLUE [4]~[9]

// shape 1, 2, 3
// ㅁ ㅁㅁ ㅁ|ㅁ

int score = 0;

int chk(int shape, int x, int y, int color) {
	
	if (color == 1) {
		if (shape == 1) {
			if (x + 1 > 9 || map[y][x+1] != 0) {
				return 1;
			}
		}
		else if (shape == 2) {
			if (x + 2 > 9 || map[y][x + 2] != 0) {
				return 1;
			}
		}
		else {
			if (x + 1 > 9 || map[y][x + 1] != 0 || map[y + 1][x + 1] != 0) {
				return 1;
			}
		}
	}
	else {
		if (shape == 1) {
			if (y + 1 > 9 || map[y + 1][x] != 0) {
				return 1;
			}

		}
		else if (shape == 2) {
			if (y + 1 > 9 || map[y + 1][x] != 0 || map[y + 1][x + 1] != 0) {
				return 1;
			}
		}
		else {
			if (y + 2 > 9 || map[y + 2][x] != 0) {
				return 1;
			}
		}
	}
	return 0;
}


void push(int shape, int x, int y) {

	//BLUE//
	int bx = x;
	while (1) {
		if (chk(shape, bx, y, 1)) {
			break;
		}
		bx++;
	}

	if (shape == 2) {
		map[y][bx + 1] = 1;
	}
	else if (shape == 3) {
		map[y + 1][bx] = 1;
	}
	map[y][bx] = 1;

	int gy = y;
	while (1) {
		if (chk(shape, x, gy, 2)) {
			break;
		}
		gy++;
	}

	if (shape == 2) {
		map[gy][x + 1] = 1;
	}
	else if (shape == 3) {
		map[gy + 1][x] = 1;
	}
	map[gy][x] = 1;

}

void clear() {

	int temp;
	int c;
	int clear = 0;

	// BLUE 
	for (int i = 9; i > 5; i--) {
		if (map[0][i] == 1 && map[1][i] == 1 && map[2][i] == 1 && map[3][i] == 1) {
			score++;

			map[0][i] = 0; map[1][i] = 0; map[2][i] = 0; map[3][i] = 0;
			c = i;
			while (c - 1 > 3) {
				temp = map[0][c]; map[0][c] = map[0][c - 1]; map[0][c - 1] = temp;
				temp = map[1][c]; map[1][c] = map[1][c - 1]; map[1][c - 1] = temp;
				temp = map[2][c]; map[2][c] = map[2][c - 1]; map[2][c - 1] = temp;
				temp = map[3][c]; map[3][c] = map[3][c - 1]; map[3][c - 1] = temp;
				c--;
			}
			clear = 1;
		}
		if (map[i][0] == 1 && map[i][1] == 1 && map[i][2] == 1 && map[i][3] == 1) {
			score++;

			map[i][0] = 0; map[i][1] = 0; map[i][2] = 0; map[i][3] = 0;
			c = i;
			while (c - 1 > 3) {
				temp = map[c][0]; map[c][0] = map[c - 1][0]; map[c - 1][0] = temp;
				temp = map[c][1]; map[c][1] = map[c - 1][1]; map[c - 1][1] = temp;
				temp = map[c][2]; map[c][2] = map[c - 1][2]; map[c - 1][2] = temp;
				temp = map[c][3]; map[c][3] = map[c - 1][3]; map[c - 1][3] = temp;
				c--;
			}
			clear = 1;
		}

		if (clear == 1) {
			i++;
			clear = 0;
		}
	}

	while (map[0][5] == 1 || map[1][5] == 1 || map[2][5] == 1 || map[3][5] == 1) {
		map[0][9] = 0; map[1][9] = 0; map[2][9] = 0; map[3][9] = 0;

		c = 9;
		while (c - 1 > 3) {
			temp = map[0][c]; map[0][c] = map[0][c - 1]; map[0][c - 1] = temp;
			temp = map[1][c]; map[1][c] = map[1][c - 1]; map[1][c - 1] = temp;
			temp = map[2][c]; map[2][c] = map[2][c - 1]; map[2][c - 1] = temp;
			temp = map[3][c]; map[3][c] = map[3][c - 1]; map[3][c - 1] = temp;
			c--;
		}
	}

	while (map[5][0] == 1 || map[5][1] == 1 || map[5][2] == 1 || map[5][3] == 1) {
		map[9][0] = 0; map[9][1] = 0; map[9][2] = 0; map[9][3] = 0;

		c = 9;
		while (c - 1 > 3) {
			temp = map[c][0]; map[c][0] = map[c - 1][0]; map[c - 1][0] = temp;
			temp = map[c][1]; map[c][1] = map[c - 1][1]; map[c - 1][1] = temp;
			temp = map[c][2]; map[c][2] = map[c - 1][2]; map[c - 1][2] = temp;
			temp = map[c][3]; map[c][3] = map[c - 1][3]; map[c - 1][3] = temp;
			c--;
		}
	}
}

void cnt() {
	int tile = 0;

	for (int i = 6; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 1) {
				tile++;
			}
			if (map[j][i] == 1) {
				tile++;
			}
		}
	}

	printf("%d\n", tile);

}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int s;
		int x; int y;
		scanf("%d %d %d", &s, &y, &x);
		push(s, x, y);
		clear();
	}

	printf("%d\n", score);

	// count // 
	cnt();

	return 0;
}