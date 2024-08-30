#include <stdio.h>
#pragma warning(disable:4996)

int N;
int P;

int hand[7][300003];
int tp[7];

void push(int line, int pret) {
	hand[line][tp[line]++] = pret;
	return;
}

void pop(int line) {
	tp[line]--;
	return;
}

int top(int line) {
	return hand[line][tp[line]-1];
}


int main() {

	scanf("%d %d", &N, &P);
	
	int LineN;
	int PretN;

	int move = 0;

	for (int i = 0; i < N; i++) {

		scanf("%d", &LineN);
		scanf("%d", &PretN);

		if (PretN > top(LineN)) {
			push(LineN, PretN);
			move++;
		}
		else if (PretN < top(LineN)) {



			while (PretN < top(LineN)) {

				pop(LineN);
				move++;
			}

			if (PretN == top(LineN)) {
				continue;
			}
		
			push(LineN, PretN);
			move++;
		}

	}


	printf("%d", move);

	return 0;
}