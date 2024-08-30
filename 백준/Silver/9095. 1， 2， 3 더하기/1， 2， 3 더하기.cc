#include <stdio.h>
#pragma warning(disable:4996)

int dp[20];
int T;

void test() {

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}



}

int main() {

	scanf("%d", &T);

	test();

	int a;
	for (int i = 0; i < T; i++) {
		scanf("%d", &a);
		printf("%d\n", dp[a]);
	}


	return 0;
}
