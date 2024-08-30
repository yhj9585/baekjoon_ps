#include <stdio.h>

int main() {
	int s[1000002];
	int n;
	scanf("%d", &n);



	int higher = 0;
	int lower = 0;
	int high = 1;
	int low = 1;

	scanf("%d", &s[0]);

	for (int i = 1; i < n; i++) {
		scanf("%d", &s[i]);

		if (s[i] < s[i - 1]) {
			low += 1;
			high = 1;
		}
		if (s[i] > s[i - 1]) {
			high += 1;
			low = 1;
		}
		if (s[i] == s[i - 1]) {
			low++;
			high++;
		}

		if (high > higher) {
			higher = high;
		}
		if (low > lower) {
			lower = low;
		}
	}

	if (n == 1) {
		higher = 1;
	}

	if (higher >= lower) {
		printf("%d", higher);
	}
	else {
		printf("%d", lower);
	}
}