#include <stdio.h>
#pragma warning(disable:4996)

int Tn[60];

void prev() {
	for (int i = 1; i < 50; i++) {
		Tn[i] = i * (i + 1) / 2;
	}
}

void test(int k) {

	int sum = 0;
	for (int i = 1; i < 60; i++) {
		if (k > Tn[i]) {
			sum += Tn[i];
			
			// 2
			for (int j = 1; j < 60; j++) {
				if (k > Tn[j] + sum) {
					sum += Tn[j];

					// 3
					for (int l = 1; l < 60; l++) {
						if (k == Tn[l] + sum) {
							printf("1\n");
							return;
						}
						else if (Tn[l] + sum > k) {
							break;
						}
					}


				}
				else if (Tn[j] + sum >= k) {
					break;
				}

				sum -= Tn[j];
			}

		}
		else if (Tn[i] >= k) {
			break;
		}
		sum -= Tn[i];

	}

	printf("0\n");
}

int main() {

	int T, K;
	scanf("%d", &T);
	
	prev();

	for (int i = 0; i < T; i++) {
		scanf("%d", &K);

		test(K);
	}
	

	return 0;
}