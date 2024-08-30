#include <stdio.h>
#pragma warning(disable:4996)

int N;
int dp[1004] = { 0, };

void block() {

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	printf("%d", dp[N]);


}


int main() {

	scanf("%d", &N);

	block();



	return 0;
}