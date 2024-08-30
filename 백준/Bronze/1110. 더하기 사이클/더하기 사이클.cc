#include <stdio.h>

int main() {
	int number[1000];
	scanf("%d", &number[0]);

	for (int i = 1; true; i++) {
		int a = number[i - 1] % 10;
		int b = (number[i - 1] / 10 + number[i - 1] % 10) % 10;
		number[i] = a * 10 + b;
		if (number[i] == number[0]) {
			printf("%d", i);
			break;
		}
	}
}