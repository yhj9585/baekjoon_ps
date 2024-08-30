#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int up[1001] = { 0, };

	for (int i = 0; i < n; i++) {
		scanf("%d", &up[i]);
	
	}
	int f_height = 0, fir = 0, fin = 0, real = 0;
	for (int i = 1; i < n; i++) {
		int height = 0;
		if  ((up[i] > up[i - 1]) && (i == 1)) {
			fir = up[i - 1];
			real = 1;
		}
		else if ((up[i] > up[i - 1]) && (up[i - 1] <= up[i - 2]) && (real == 0)) {
			fir = up[i - 1];
			real = 1;
		}
		else if (up[i] <= up[i - 1] && real) {
			fin = up[i - 1];
			height = fin - fir;
			real = 0;
		}
		if (up[i] > up[i-1] && i+1 == n ) {
			fin = up[i];
			height = fin - fir;
			real = 0;

		}

		if (height > f_height) {
			f_height = height;
		}
	}
	if (f_height > 0) {
		printf("%d", f_height);
	}
	else {
		printf("0");
	}
}