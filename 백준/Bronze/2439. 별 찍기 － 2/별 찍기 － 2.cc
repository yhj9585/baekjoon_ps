#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int i = 1;
	while (i <= n) {
		int j = 1;
		int x = 1;
		while (x <= n - i) {
			printf(" ");
			x++;
		}
		while (j <= i) {
			printf("*");
			j++;
		}
		printf("\n");
		i++;
	}
}