#include <stdio.h>
#pragma warning(disable :4996)
#pragma warning(disable :6031)

int H, W;
int T;

struct pos{
	int x, y;
};

pos opt[4];

// queue //
pos queue[100000];
int map[1000][1000];
int visit[1000][1000];

int head, tail;

void push(int y, int x) {
	queue[tail].x = x;
	queue[tail].y = y;

	visit[y][x] = 1;
	tail++;
}

int head_x() {
	return queue[head].x;
}
int head_y() {
	return queue[head].y;
}

void pop() {
	head++;
}

int size() {
	return tail - head;
}

void bfs(int i, int j) {
	int cur_x = head_x();
	int cur_y = head_y();

	pop();

	int move_x;
	int move_y;

	for (int p = 0; p < 4; p++) {
			
		move_x = cur_x + opt[p].x;
		move_y = cur_y + opt[p].y;

		if ((move_x >= 0 && move_y >= 0) && (move_x < W && move_y < H)) {
			if (map[move_y][move_x] == 1 && visit[move_y][move_x] == 0) {
				push(move_y, move_x);
				bfs(move_y, move_x);
			}



		}


	}

	
}


// H - y
// W -x 
int main() {
	//////////////
	opt[0].x = 0;
	opt[0].y = -1;
	opt[1].x = 0;
	opt[1].y = 1;
	opt[2].x = -1;
	opt[2].y = 0;
	opt[3].x = 1;
	opt[3].y = 0;
	//////////////

	scanf("%d", &T);
	
	for (int a = 0; a < T; a++) {
		scanf("%d %d", &H, &W);
		head = 0;
		tail = 0;
		
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				visit[y][x] = 0;
				map[y][x] = 0;
			}
		}

		

		char inPut;
		for (int y = 0; y < H; y++) {
			getchar();
			for (int x = 0; x < W; x++) {
				scanf("%1c", &inPut);


				if (inPut == '.') {
					map[y][x] = 0;
				}
				else if (inPut == '#') {
					map[y][x] = 1;
				}
			}
		}

		int group = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (visit[i][j] == 0 && map[i][j] == 1) {
					push(i, j);
					bfs(i, j);
					group++;
				}
				

			}
		}

		printf("%d\n", group);

		for (int i = 0; i < tail; i++) {
			queue[i] = { 0,0 };
		}

	}


}