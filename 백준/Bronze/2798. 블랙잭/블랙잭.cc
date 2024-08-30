#include <stdio.h>
#pragma warning(disable:4996)

int N; int M;
int cards[101];

int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &cards[i]);
	}

	int a;
	int large = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			for (int k = j; k < N; k++) {
				if (i != j && j != k) {

					a = cards[i] + cards[j] + cards[k];
					if (a > large&& a <= M) {
						large = a;
					}
				}

			}
		}
	}


	printf("%d", large);


	return 0;
}