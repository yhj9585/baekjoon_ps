#include <stdio.h>
#pragma warning(disable:4996) 

int A, B, V;

int left, right, mid;

void ping() {

	int sav;
	int mid_L;
	left = 1;
	right = V / (A - B) + 1;
	// Large = right*(A-B) + B

	if (A >= V) {
		printf("1");
		return;
	}

	while (left <= right) {

		mid = (left + right) / 2;
		mid_L = mid * (A - B) + B;




		if (mid_L > V) {
			right = mid - 1;
			if (right * (A - B) + B < V) {
				break;
			}
		}
		else if (mid_L == V) {

			break;
		}
		else {
			left = mid + 1;
		}



	}
	printf("%d", mid);

}


int main() {

	scanf("%d %d %d", &A, &B, &V);
	
	ping();

	return 0;
}