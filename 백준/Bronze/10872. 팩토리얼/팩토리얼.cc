#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int pe = 1;
	for (int i = 1; i <= n; i++) {
		pe = pe * i;
	}
	printf("%d", pe);
}