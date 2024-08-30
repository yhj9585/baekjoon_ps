#include <stdio.h>

int main() {

	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	
	char number[10];
	int num = a * b * c;
	for (int i = 0; i < 10; i++) {
		if (num > 0) {
			number[i] = num % 10;
		}
		else {
			number[i] = a;
		}
		num = num / 10;
	}
	for (int x = 0; x < 10; x++) {


		int cnt = 0;
		for (int i = 0; i < 10; i++) {
			if (number[i] == x) {
				cnt += 1;
			}
		}
		printf("%d\n", cnt);
	}
	
}