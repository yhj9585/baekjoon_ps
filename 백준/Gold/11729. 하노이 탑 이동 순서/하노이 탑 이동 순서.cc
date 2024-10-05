#include <iostream>
#include <cmath>
#pragma warning(disable:4996)

int N;

void hanoi(int height, int from, int way) {
	printf("%d %d\n", from, way);

	for (int i = 1; i < height; i++) {
		//printf("\t, %d\n", i);

		if ((height - i) % 2 == 0) {
			hanoi(i, 6 - from - way, from);
		}
		else {
			hanoi(i, 6 - from - way, way);
		}
	}
}

int main() {
	scanf("%d", &N);

	int ans = ((int)pow(2, N)) - 1;

	printf("%d\n", ans);

	for (int i = 1; i <= N; i++) {
		//printf("first: %d\n", i);
		if ((N - i) % 2 == 0) {
			hanoi(i, 1, 3);
		}
		else {
			hanoi(i, 1, 2);
		}
	}

	return 0;
}