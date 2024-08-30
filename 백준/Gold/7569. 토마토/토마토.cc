#include <stdio.h>
#pragma warning(disable:4996)

int M, N, H;
int box[101][101][101];
int visit[101][101][101] = { 0, };

struct node {
	int x, y, z;
};

node spread[6] = {
	{-1,  0,  0},
	{ 1,  0,  0},
	{ 0, -1,  0},
	{ 0,  1,  0},
	{ 0,  0, -1},
	{ 0,  0,  1}
};

node queue[10000001] = { 0, };
int st, ed;

// queue //
void push(node n) {
	queue[ed++] = n;
	return;
}

node pop() {
	return queue[st++];
}

int size() {
	return ed - st;
}

node nxt(node n_pos, int i) {
	
	node nxt_pos;
	nxt_pos.x = n_pos.x + spread[i].x;
	nxt_pos.y = n_pos.y + spread[i].y;
	nxt_pos.z = n_pos.z + spread[i].z;

	return nxt_pos;
}

int scale(node n_pos) {
	if (n_pos.x >= 0 && n_pos.y >= 0 && n_pos.z >= 0) {
		if (n_pos.x < M && n_pos.y < N && n_pos.z < H) {
			return 1;
		}
	}

	return 0;
}

// bfs //
void bfs() {
	while (size() != 0) {
		node n_pos = pop();
		node nxt_pos;
		
		for (int i = 0; i < 6; i++) {
			nxt_pos = nxt(n_pos, i);

			if (scale(nxt_pos)) {
				
				if (box[nxt_pos.z][nxt_pos.y][nxt_pos.x] == 0 && visit[nxt_pos.z][nxt_pos.y][nxt_pos.x] == 0) {
					push(nxt_pos);
					visit[nxt_pos.z][nxt_pos.y][nxt_pos.x] = visit[n_pos.z][n_pos.y][n_pos.x] + 1;
				}
			}
		}
	}
}


void rotten() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				
				if (box[i][j][k] == 1 && visit[i][j][k] == 0) {
					node ths_node = { k, j, i };
					visit[ths_node.z][ths_node.y][ths_node.x] = 1;
					push(ths_node);
				}
			}
		}
	}

	bfs();

	// test //
	int longest = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				
				// time test //
				if (box[i][j][k] != -1) {
					if (visit[i][j][k] > longest) {
						longest = visit[i][j][k];
					}
				}

				// impossible test // 
				if (box[i][j][k] == 0 && visit[i][j][k] == 0) {
					printf("-1\n");
					return;
				}
			}
		}
	}
	printf("%d\n", longest - 1);
}




int main() {
	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &box[i][j][k]);
			}
		}
	}
	rotten();
    
	return 0;
}