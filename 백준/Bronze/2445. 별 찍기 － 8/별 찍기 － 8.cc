#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int x = 1; x <= i; x++) {
			printf("*");
		}
		for (int x = 1; x <= (n - i) * 2; x++) {
			printf(" ");
		}
		for (int x = 1; x <= i; x++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n - 1; i > 0; i--) {
		for (int x = 1; x <= i; x++) {
			printf("*");
		}
		for (int x = 1; x <= (n - i) * 2; x++) {
			printf(" ");
		}
		for (int x = 1; x <= i; x++) {
			printf("*");
		}
		printf("\n");
	}
}