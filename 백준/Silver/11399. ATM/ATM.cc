#include <stdio.h>
#pragma warning(disable:4996)

int N;
int people[1005];

void qsort(int left, int right) {

	int mid;
	int ptr1;
	int ptr2;
	int tmp;

	if (left < right) {
		ptr1 = left - 1;
		ptr2 = right + 1;

		mid = people[(left + right) / 2];

		while (1) {
			while (people[++ptr1] < mid);
			while (people[--ptr2] > mid);

			if (ptr1 >= ptr2) {
				break;
			}

			tmp = people[ptr1];
			people[ptr1] = people[ptr2];
			people[ptr2] = tmp;
		}

		qsort(left, ptr1 - 1);
		qsort(ptr2 + 1, right);
	}


}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &people[i]);
	}

	qsort(0, N-1);

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += people[i] * (N-i);
	}

	printf("%d", sum);

	return 0;
}