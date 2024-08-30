#include <stdio.h>
#pragma warning(disable:4996)

int C;

// stack //
int player[20][20];
int chk[20];
int stack[20];
int tp;

void push(int a) {
	stack[tp++] = a;
	return;
}

int pop() {
	return stack[--tp];
}

int size() {
	return tp;
}

void reset() {
	tp = 0;
	return;
}

int large = 0;
int ability;

void dfs(int n) {
	if (n == 11) {
		if (ability > large) {
			large = ability;
		}
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (chk[i] == 0 && player[i][n] != 0) {
			push(i);
			chk[i] = 1;
			ability += player[i][n];

			dfs(n + 1);

			ability -= player[i][n];
			pop();
			chk[i] = 0;
		}
	}

	return;

}



int main() {

	scanf("%d", &C);

	for (int c = 0; c < C; c++) {
		ability = 0;
		large = 0;
		reset();

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				scanf("%d", &player[i][j]);
			}
		}

		dfs(0);

		printf("%d\n", large);
	
	}
	return 0;
}