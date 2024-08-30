#include <stdio.h>

int main() {
	int n[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d", &n[i]);
	}
	int large;
	int mid;
	int small;

	for (int i = 0; i < 3; i++) {
		if ((n[i] >= n[0]) && (n[i] >= n[1]) && (n[i] >= n[2])) {
			large = n[i];
		}
		else if ((n[i] <= n[0]) && (n[i] <= n[1]) && (n[i] <= n[2])) {
			small = n[i];
		}
		else {
			mid = n[i];
		}

		
	}
	printf("%d ", small);
	printf("%d ", mid);
	printf("%d ", large);
}