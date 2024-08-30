#include <stdio.h>
#pragma warning(disable : 4996)

//queue
#define SIZE 100000

int q[SIZE] = { 0, };
int st = 0, ed = 0;

int subin, bro;

void push(int n) {
	q[st++] = n;
}

void pop() {
	if (st == ed) {
		printf("error\n");
	}
	ed++;
}

int first() {
	return q[ed];
}

int final() {
	return q[st];
}

int size() {
	return st - ed;
}

int visit[100001] = { 0, };

int main() {
	scanf("%d %d", &subin, &bro);
	//printf("%d %d", subin, bro);
	
	push(subin);
	visit[subin] = 1;

	

	while (size() != 0) {
		int pos = first();
		//printf("%d %d \n", st, ed);
		pop();

		if (pos + 1 <= 100000 && visit[pos + 1] == 0) {
			push(pos + 1);
			visit[pos + 1] = visit[pos] + 1;
		}
		if (pos - 1 <= 100000 && visit[pos - 1] == 0) {
			push(pos - 1);
			visit[pos - 1] = visit[pos] + 1;
		}
		if (pos * 2 <= 100000 && visit[pos * 2] == 0) {
			push(pos * 2);
			visit[pos * 2] = visit[pos] + 1;
		}

		//for (int i = 1; i <= bro; i++) {
		//	printf("%d ", visit[i]);
		//}
		//printf("\n");


		if (visit[bro] != 0) {
			printf("%d", visit[bro]-1);
			break;
		}

	}
}
