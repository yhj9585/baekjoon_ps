#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int small = 1000001;
	int large = -1000001;
	int num = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num > large) {
			large = num;
		}
		if (num < small) {
			small = num;
		}
	}
	printf("%d %d", small, large);
}