#include <iostream>
#pragma warning(disable:4996)



int main() {
	int N;
	scanf("%d", &N);

	unsigned long long sum = 1;
	for (int i = 1; i <= N; i++) {
		sum *= i;
	}

	printf("%llu\n", sum);

	
	return 0;
}