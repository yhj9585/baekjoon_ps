#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996) 

//int map[5][5];

int chk[25];
int result;

struct pos {
	int x, y;
	int opt;
};

pos linear[25];

// stack //
pos stack[10];
int tp;

void s_push(pos n) {
	stack[tp++] = n;
	return;
}
void s_pop() {
	--tp;
	return;
}
int s_size() {
	return tp;
}

void bfs();


int ysize;
void dfs(int a) {
	if (s_size() == 7) {

		/*
		for (int i = 0; i < 7; i++) {
			printf("(%d,%d) ", stack[i].x, stack[i].y);
		}
		printf("\n");
		*/
		bfs();
		return;
	}

	for (int i = a; i < 25; i++) {
	
		if (chk[i] == 0) {
			if (linear[i].opt == 0) {
				if (ysize >= 3) {
					continue;
				}
				ysize++;
			}
			chk[i] = 1;
			s_push(linear[i]);
			dfs(i + 1);

			if (linear[i].opt == 0) {
				ysize--;
			}
			chk[i] = 0;
			s_pop();
		}
	}
	
}

// queue //
pos queue[10];
int st, ed;

void q_push(pos n) {
	queue[ed++] = n;
	return;
}
pos q_pop() {
	return queue[st++];
}
int q_size() {
	return ed - st;
}


void bfs() {
	int check[7] = { 0, };
	st = 0;
	ed = 0;

	q_push(stack[0]);
	check[0] = 1;

	int c = 1;

	pos n;
	while (q_size() != 0) {
		n = q_pop();

		for (int i = 0; i < 7; i++) {
			if (check[i] == 0) {
				int x = abs(n.x - stack[i].x);
				int y = abs(n.y - stack[i].y);

				if ((x + y) <= 1) {
					q_push(stack[i]);
					c++;
					check[i] = 1;
				}
			}
		}

		if (c == 7) {
			result++;
			return;
		}
	}
}

int main() {

	int e = 0;

	char a;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%1c", &a);
			if (a == 'Y') {
				linear[e] = { j ,i, 0 };
			}
			else {
				linear[e] = { j ,i, 1 };
			}
			e++;
		}
		getchar();
	}



	dfs(0);
	printf("%d\n", result);


	return 0;
}