#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int x = 1; x < i; x++) {
			printf(" ");
		}
		for (int x = 1; x < 2 * (n-i+1); x++) {
			printf("*");
		}
		printf("\n");
	}
}