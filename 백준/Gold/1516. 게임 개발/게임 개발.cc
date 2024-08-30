#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	int inLine;
	int outLine;
}node;

node house[501] = { 0, };
int LineOut[501][501] = { 0, };
int LineIn[501][501] = { 0, };
int resultTP[501] = { 0, };
int resultDP[501] = { 0, };

int N;

int queue[500] = { 0, };
int st; int ed;
void push(int newnode) {
	queue[st++] = newnode;
	return;
}
int pop() {
	return queue[ed++];
}
int size() {
	return st - ed;
}

int main() {
	int inputint = 0;
	int houseN = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &inputint);
		house[i].num = inputint;

		while (inputint != -1) {
			scanf("%d", &inputint);
			if (inputint != -1) {
				LineIn[i][house[i].inLine++] = inputint;
				LineOut[inputint][house[inputint].outLine++] = i;
			}
			else {
				break;
			}
		}
	}

	int tempinLine[501] = { 0, };
	for (int i = 1; i <= N; i++) {
		tempinLine[i] = house[i].inLine;
	}

	// TopLology
	for (int i = 1; i <= N; i++) {
		if (tempinLine[i] == 0) {
			push(i);
		}
	}

	int nowptr = 0;
	for (int i = 1; i <= N; i++) {
		nowptr = pop();
		resultTP[i] = nowptr;
		for (int j = 0; j < house[nowptr].outLine; j++) {
			if (--tempinLine[LineOut[nowptr][j]] == 0) {
				push(LineOut[nowptr][j]);
			}
		}
	}



	// DP
	int longest = 0;
	for (int i = 1; i <= N; i++) {
		longest = 0;
		nowptr = resultTP[i];
		resultDP[nowptr] += house[nowptr].num;
		for (int j = 0; j < house[nowptr].inLine; j++) {
			if (longest < resultDP[LineIn[nowptr][j]]) {
				longest = resultDP[LineIn[nowptr][j]];
			}
		}
		resultDP[nowptr] += longest;
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", resultDP[i]);
	}


	return 0;
}