#include <stdio.h>
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

int n, m;

struct pos {
	int x, y;
};

pos move[4] = { {0,-1}, {0,1}, {-1, 0}, {1, 0} };

// queue //
int map[1000][1000];
int visit[1000][1000];

pos queue[1000000];

int st, ed;

void push(pos value) {
	visit[value.y][value.x] = 1;
	queue[ed++] = value;
}
pos pop() {
	return queue[st++];
}



int scale;

void bfs() {
	pos cur_Pos = pop();
	pos nxt_Pos;

	for (int a = 0; a < 4; a++) {
		nxt_Pos.x = cur_Pos.x + move[a].x;
		nxt_Pos.y = cur_Pos.y + move[a].y;

		if ((nxt_Pos.x >= 0 && nxt_Pos.y >= 0) && (nxt_Pos.y < n && nxt_Pos.x < m)) {
			if (map[nxt_Pos.y][nxt_Pos.x] == 1 && visit[nxt_Pos.y][nxt_Pos.x] == 0) {
				scale++;
				push(nxt_Pos);
				bfs();
			}
		}


	}


}

int n_Paint;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	pos n_Pos;
	int scale_L = 0;
	
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (map[j][i] == 1 && visit[j][i] == 0) {
				scale = 1;
				n_Pos = { i, j };
				push(n_Pos);
				bfs();
				n_Paint++;

				if (scale > scale_L) {
					scale_L = scale;
				}
			}
		}
	}

	printf("%d\n", n_Paint);
	printf("%d\n", scale_L);
}