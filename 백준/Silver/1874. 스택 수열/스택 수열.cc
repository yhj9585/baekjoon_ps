#include <stdio.h>
#pragma warning(disable:4996)

int N;
int line[100001];
char done[200002];

// stack //
int stack[100001];
int tp;

void push(int v) {
	stack[tp++] = v;
	return;
}

int pop() {
	return stack[--tp];
}

int size() {
	return tp;
}

int top() {
	return stack[tp-1];
}

void stacker() {

	int n = 0;
	int i = 1;
	int doneN = 0;


	while (i <= line[n]) {

		push(i);
		done[doneN++] = '+';
		i++;

		while (line[n] == top() && top() != 0) {
			pop();
			n++;
			done[doneN++] = '-';
		}

		if (n == N) {
			break;
		}

	}

	if (size() == 0) {

		for (int a = 0; a < doneN; a++) {
			printf("%c\n", done[a]);
		}
	}

	else {
		printf("NO\n");
	}

}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &line[i]);
	}

	stacker();

}