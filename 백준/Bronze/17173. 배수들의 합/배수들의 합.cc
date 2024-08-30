#include <stdio.h>
#pragma warning (disable: 4996)

int main() {
	int m;
	int n;
	int K[1000] = { 0 };


	int sum = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf(" %d", &K[i]);
	}

	//printf("n = %d, m = %d\n", n, m);


	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (i % K[j] == 0) {
				sum += i;
				break;
			}
		}


	}

	printf("%d", sum);

}

