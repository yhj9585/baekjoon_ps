#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int x = 1; x < n - i+ 1; x++) {
			printf(" ");
		}
		for (int x = 1; x < 2 * i; x++) {
			printf("*");
		}
		printf("\n");
	}
}