#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 10000


int st, ed;

struct {
	int x, y;
}q[SIZE];

// queue //
void push(int x, int y) {
	q[st++] = { x, y };
}

void pop() {
	ed++;
}

int first_x() {
	return q[ed].x;
}

int first_y() {
	return q[ed].y;
}

int end_x() {
	return q[st].x;
}

int end_y() {
	return q[st].y;
}

int size() {
	return st - ed;

}

int ground[30][30] = { 0, };
int visit[30][30] = { 0, };

int x, y;
int N;
int count;
int count_arr[1000];

int bfs(int base_x, int base_y) {
	count = 0;
	visit[base_y][base_x] = 1;
	push(base_x, base_y);
	//printf("base: (%d, %d)\n", base_x, base_y);

	while (size() != 0) {
		x = first_x();
		y = first_y();
		pop();
		//printf("(%d, %d)\n", x, y);

		if (visit[y][x + 1] == 0 && ground[y][x + 1] == 1 && x + 1 < N) {
			push(x + 1, y);
			visit[y][x + 1] = 1;
		}
		if (visit[y][x - 1] == 0 && ground[y][x - 1] == 1 && x - 1 >= 0) {
			push(x - 1, y);
			visit[y][x - 1] = 1;
		}
		if (visit[y + 1][x] == 0 && ground[y + 1][x] == 1 && y + 1 < N) {
			push(x, y + 1);
			visit[y + 1][x] = 1;
		}
		if (visit[y - 1][x] == 0 && ground[y - 1][x] == 1 && y - 1 >= 0) {
			push(x, y - 1);
			visit[y - 1][x] = 1;
		}

		count++;
	}
	return count;
	//printf("\n\n");
}








int main() {
	int complex;


	scanf("%d", &N);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &ground[i][j]);
		}
	}


	/*
	for (int c = 0; c < cabbage_n; c++) {
		int c_x, c_y;

		scanf("%d %d", &c_x, &c_y);
		ground[c_y][c_x] = 1;
	}
	*/

	/*
	printf("\n\n");
	// 배열 정상적으로 받았는지 확인
	for (int b = 0; b < N; b++) {
		for (int a = 0; a < N; a++) {
			printf("%d ", ground[b][a]);
		}
		printf("\n");
	}
	*/

	complex = 0;
	for (int b = 0; b < N; b++) {
		for (int a = 0; a < N; a++) {
			if (ground[b][a] == 1 && visit[b][a] == 0) {
				count_arr[complex] = bfs(a, b);

				complex++;
			}
		}
	}

	printf("%d\n", complex);

	/*
	for (int i = 0; i < complex; i++) {
		printf("%d ", count_arr[i]);
	}
	*/

	int temp;
	for (int i = 1; i < complex; i++) {
		for (int j = 0; j < complex-i; j++) {
			if (count_arr[j] > count_arr[j + 1]) {
				temp = count_arr[j];
				count_arr[j] = count_arr[j + 1];
				count_arr[j + 1] = temp;
			}
		}
	}


	for (int i = 0; i < complex; i++) {
		printf("%d\n", count_arr[i]);
	}


}


