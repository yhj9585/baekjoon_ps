#include <stdio.h>
#pragma warning(disable:4996)

int N;
int ropes[100005];
int a;
int L;


void test() {

	int n = 0;
	int Lw = 0;
	int Rn = 0;

	for (int i = 1; i < L+1; i++) {

		while (ropes[i] > 0) {

			n++;
			if (Rn == 0) {
				Rn = 1;
				Lw = i;
			}
			else if ( i * (N - n + 1) > (N - Rn + 1) * Lw ) {
				Rn = n;
				Lw = i;
			}
			ropes[i]--;
		}
	}

	printf("%d", (N - Rn + 1) * Lw);



}


int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		ropes[a] += 1;

		if (a > L) {
			L = a;
		}
	}

	test();

	return 0;
};