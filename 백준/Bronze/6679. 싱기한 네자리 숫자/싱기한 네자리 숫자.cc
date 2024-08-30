#include <stdio.h>

int total(int num, int n) {
	
	int add = 0;

	while (num > 0) {
		add += num % n;
		num -= num % n;
		num = num / n;
		if (num < n) {
			add += num;
			break;
		}
	}

	return add;

}


int main() {
	for (int i = 1000; i < 10000; i++) {
		int tot1 = total(i, 10);
		int tot2 = total(i, 12);
		int tot3 = total(i, 16);

		if (tot1 == tot2 && tot2 == tot3) {
			printf("%d\n", i);
		}

	}

}