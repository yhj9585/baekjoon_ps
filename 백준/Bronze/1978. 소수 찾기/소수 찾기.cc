#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int number;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &number);
		if (number == 2) {
			cnt++;
		}
		for (int j = 2; j < number; j++) {
			if (number % j == 0) {
				break;
			}
			if (number - 1 == j) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}