#include <stdio.h>

int H; int W;
int fullClean = 0;
int cleaned = 0;

int ArisuY; int ArisuX; int ArisuDir;

int map[70][70] = { 0, };
int rule[2][70][70] = { 0, };

int move[4][2] = { // CLOCKWISE
	{-1, 0},	// 0 UP
	{ 0, 1},	// 1
	{ 1, 0},	// 2
	{ 0,-1}		// 3
};

void simul() {
	int moved = 0;
	int unclean = 1;

	int cycle = 0; int stY = 0; int stX = 0; int stD = 0;
	int savmoved = 0;

	while (cleaned != fullClean) {
		unclean = 1;
		if (map[ArisuY][ArisuX] == 0) {
			map[ArisuY][ArisuX] = 1;
			unclean = 0;
			cleaned++;
			cycle = 0;
			savmoved = 0;
		}

		ArisuDir += rule[unclean][ArisuY][ArisuX];
		if (ArisuDir > 3) {
			ArisuDir -= 4;
		}
		ArisuY += move[ArisuDir][0];
		ArisuX += move[ArisuDir][1];

		moved++;

		// OVER BOUND
		if (ArisuY >= H || ArisuY < 0 || ArisuX >= W || ArisuX < 0) {
			if (cycle == 1) {
				printf("%d\n", savmoved);
			}
			else {
				printf("%d\n", moved);
			}
			return;
		}
		// Cycle Check
		if (cycle == 1 && ArisuY == stY && ArisuX == stX && ArisuDir == stD) {
			printf("%d\n", savmoved);
			return;
		}

		if (unclean == 0 && map[ArisuY][ArisuX] == 1) {
			stY = ArisuY;
			stX = ArisuX;
			stD = ArisuDir;
			savmoved = moved;
			cycle = 1;
		}
		
		if (cleaned == fullClean) {
			printf("%d\n", moved);
			return;
		}

	}
}

int main() {
	scanf("%d %d", &H, &W);
	scanf("%d %d %d", &ArisuY, &ArisuX, &ArisuDir);

	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%1d", &rule[z][i][j]);
			}
		}
	}

	fullClean = H * W;

	simul();
	return 0;
}