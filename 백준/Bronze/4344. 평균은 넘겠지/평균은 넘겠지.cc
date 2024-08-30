#include <stdio.h>

int main() {
	int test_case;
	scanf("%d", &test_case);
	for (int j = 0; j < test_case; j++) {
		int a[1000];
		int student_n;
		int sum = 0;

		scanf("%d", &student_n);

		for (int i = 0; i < student_n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}

		int cnt = 0;
		for (int i = 0; i < student_n; i++) {
			if (a[i] > (double)sum / student_n) {
				cnt++;
			}
		}
		printf("%.3f%%\n", (double)cnt / student_n * 100);
	}
}