#include <stdio.h>
#pragma warning (disable: 4996)

int main() {
	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}