#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	
	int n1 = b % 10;
	int n2 = b % 100 / 10 ;
	int n3 = b / 100;

	int x1 = a * n1;
	int x2 = a * n2;
	int x3 = a * n3;

	printf("%d\n", x1 );
	printf("%d\n", x2 );
	printf("%d\n", x3 );

	int fin = x1 + x2 * 10 + x3 * 100;

	printf("%d", fin);
}