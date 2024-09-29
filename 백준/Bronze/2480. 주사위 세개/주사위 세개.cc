#include <iostream>
#pragma warning (disable:4996)

int a; int b; int c;

int main() {
	int value = 0;

	scanf("%d %d %d", &a, &b, &c);

	int large = 0;


	if (a == b && b == c) {
		value += 10000;
		value += a * 1000;
	}
	else if (a == b) {
		value += 1000;
		value += a * 100;
	}
	else if (b == c) {
		value += 1000;
		value += b * 100;
	}
	else if (c == a) {
		value += 1000;
		value += c * 100;
	}
	else {
		large = a;
		if (b > large) {
			large = b;
		}
		if (c > large) {
			large = c;
		}

		value += large * 100;


	}

	printf("%d\n", value);

	return 0;
}