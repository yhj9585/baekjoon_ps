#include <stdio.h>
#pragma warning (disable : 4996)

#define SIZE 100

int s[SIZE];

int tp;

// stack //
void push(int n) {
	s[tp++] = n;
}

void pop() {
	tp--;
}

int top() {
	return s[tp];
}

int size() {
	return tp;
}

void printStack() {
	for (int i = 0; i < tp; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");
}


void cleanStack() {
	while (size() != 0) {
		pop();
	}
}

int N, M;
int visit[SIZE];
int round;

void num(int t, int a) {
	if (visit[a] == 1) return;
	push(a);
	visit[a] = 1;


	if (size() != M) {
		for (int n = a+1; n <= N; n++) {
			num(t + 1, n);
		}
	}

	if (size() == M) {
		printStack();
	}
	visit[a] = 0;
	pop();
}



int main() {
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		num(1, i);
	}

}