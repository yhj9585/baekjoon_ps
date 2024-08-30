#include <stdio.h>
#pragma warning(disable:4996)

struct pos {
	int x, y;
};

pos move[4] = {
	{-1,  0}, // LEFT
	{ 0,  1}, // UP
	{ 1,  0}, // RIGHT
	{ 0, -1}  // DOWN
};

int changeDir(char nxt, int dir) {
	if (nxt == 'L') {
		if (dir == 0) {
			return 3;
		}
		else {
			return dir - 1;
		}
	}
	else {
		if (dir == 3) {
			return 0;
		}
		else {
			return dir + 1;
		}
	}
}

int main() {
	int testcase;
	char nxt = 'a';
	scanf("%d", &testcase);
	getchar();
	for (int i = 0; i < testcase; i++) {
		int xH = 0; int xL = 0;
		int yH = 0; int yL = 0;

		pos nPos = { 0, 0 };
		int dir = 1;

		while (1) {

			scanf("%1c", &nxt);
			if (nxt == '\n') {
				break;
			}

			if (nxt == 'F') {
				nPos.x = nPos.x + move[dir].x;
				nPos.y = nPos.y + move[dir].y;
			}
			else if (nxt == 'B') {
				nPos.x = nPos.x - move[dir].x;
				nPos.y = nPos.y - move[dir].y;
			}
			else {
				dir = changeDir(nxt, dir);
			}

			if (nPos.x > xH) {
				xH = nPos.x;
			}
			if (nPos.x < xL) {
				xL = nPos.x;
			}
			if (nPos.y > yH) {
				yH = nPos.y;
			}
			if (nPos.y < yL) {
				yL = nPos.y;
			}

		}

		printf("%d\n", (xH - xL) * (yH - yL));

	}
	






}