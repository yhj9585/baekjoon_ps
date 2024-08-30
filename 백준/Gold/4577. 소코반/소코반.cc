#include <stdio.h>
#pragma warning(disable:4996)

int R, C;
int Lv;
char map[20][20];
char key[60];

struct pos {
	int x, y;
};

pos move[4] = {
	{ 0, -1},  // Up
	{ 0,  1},  // Down
	{-1,  0},  // Left
	{ 1,  0}   // Right
};



pos nxtpos(pos npos, char c) {
	pos nxt;
	if (c == 'U') {
		nxt.x = npos.x + move[0].x;
		nxt.y = npos.y + move[0].y;
	}
	else if (c == 'D') {
		nxt.x = npos.x + move[1].x;
		nxt.y = npos.y + move[1].y;
	}
	else if (c == 'L') {
		nxt.x = npos.x + move[2].x;
		nxt.y = npos.y + move[2].y;
	}
	else {
		nxt.x = npos.x + move[3].x;
		nxt.y = npos.y + move[3].y;
	}

	return nxt;
}

int boxchk(pos nbox, char c, char box) {

	pos nxtbox;
	nxtbox = nxtpos(nbox, c);

	if (map[nxtbox.y][nxtbox.x] == '#' || map[nxtbox.y][nxtbox.x] == 'b' || map[nxtbox.y][nxtbox.x] == 'B') {
		return 0;
	}

	if (map[nxtbox.y][nxtbox.x] == '.') {
		map[nxtbox.y][nxtbox.x] = 'b';
	}
	else if (map[nxtbox.y][nxtbox.x] == '+') {
		map[nxtbox.y][nxtbox.x] = 'B';
	}
	
	if (box == 'b') {
		map[nbox.y][nbox.x] = '.';
	}
	else {
		map[nbox.y][nbox.x] = '+';
	}
	return 1;
}

pos check(pos npos, pos nxt, char c) {

	if (map[nxt.y][nxt.x] == '.' || map[nxt.y][nxt.x] == '+') {

		if (map[npos.y][npos.x] == 'w') {
			map[npos.y][npos.x] = '.';
		}
		else {
			map[npos.y][npos.x] = '+';
		}


		if (map[nxt.y][nxt.x] == '.') {
			map[nxt.y][nxt.x] = 'w';
		}
		else {
			map[nxt.y][nxt.x] = 'W';
		}

		return nxt;
	}
	else {
		return npos;
	}
	


}

int test() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '+' || map[i][j] == 'b') {
				return 0;
			}
		}
	}
	printf("Game %d: complete\n", Lv);
	return 1;
}

void play(pos npos) {

	pos nxt;
	int i = 0;
	while (key[i] != '\n') {

		nxt = nxtpos(npos, key[i]);

		if (map[nxt.y][nxt.x] == 'b' || map[nxt.y][nxt.x] == 'B') {
			boxchk(nxt, key[i], map[nxt.y][nxt.x]);
		}

		npos = check(npos, nxt, key[i]);

		if (test() == 1) {
			return;
		}
		i++;
	}

	printf("Game %d: incomplete\n", Lv);

	return;
}



void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

int main() {
	while (1) {
		Lv++;
		scanf("%d %d", &R, &C);
		if (R == 0 && C == 0) {
			return 0;
		}

		getchar();
		pos npos;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == 'w' || map[i][j] == 'W') {
					npos.x = j;
					npos.y = i;
				}
			}
			getchar();
		}

		for (int i = 0; i < 50; i++) {
			scanf("%c", &key[i]);
			if (key[i] == '\n') {
				break;
			}
		}

		play(npos);
		print();
	}

	return 0;
}