#include <stdio.h>
#pragma warning(disable :4996)

int N;

int fir[6] = { 2, 3, 5, 7 };
int nxt[10] = { 1, 3, 7, 9 };


void test(int num, int depth) {

	if (depth == N) {
		printf("%d\n", num);
		return;
	}

	int nxt_n;
	int nt = 0;
	for (int i = 0; i < 4; i++) {
		if (depth == 2 && num == nxt[i]) {
			continue;
		}

		nxt_n = num * 10 + nxt[i];

		for (int j = 3; j < nxt_n / 2;) {
			if (nxt_n % j == 0) {
				nt = 1;
				break;
			}
			j += 2;
		}

		if (nt == 0) {
			test(nxt_n, depth + 1);
		}
		nt = 0;
	}


}


int main() {

	scanf("%d", &N);

	for (int i = 0; i < 4; i++) {
		test(fir[i], 1);
	}

	return 0;
}