#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int i = 1;
	while (i <= n) {
		int j = n + 1 - i;
		int x = 0;
		while (x < i - 1) {
			printf(" ");
			x++;
		}
		while (j > 0) {
			printf("*");
			j--;
		}
		printf("\n");
		i++;
	}
}