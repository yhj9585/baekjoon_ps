#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int i = 1;
	while (i <= n) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
		i++;
	}
}