#include <stdio.h>
#pragma warning(disable:4996)

int mush[11];


int main() {
	
	for (int i = 0; i < 10; i++) {

		scanf("%d", &mush[i]);

	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {

		if (sum + mush[i] <= 100) {
			sum += mush[i];
		}
		else if (sum + mush[i] > 100) {

			if (100 - sum < sum + mush[i] - 100) {
				printf("%d", sum);
				return 0;
			}
			else {
				printf("%d", sum + mush[i]);
				return 0;
			}


		}


	}

	printf("%d", sum);

}