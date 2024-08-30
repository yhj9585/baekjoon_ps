#include <stdio.h>
#pragma warning(disable:4996) 

int N;
int stair[333] = { 0, };

int dp[2][333] = { 0, };


void up() {
	
	// 예외처리 //
	dp[0][1] = stair[1];
	dp[0][2] = stair[2];
	dp[1][2] = stair[2] + dp[0][1];
	
	for (int i = 3; i <= N; i++) {

		dp[1][i] = stair[i] + dp[0][i - 1];

		if (dp[0][i - 2] > dp[1][i - 2]) {
			dp[0][i] = dp[0][i - 2] + stair[i];
		}
		else {
			dp[0][i] = dp[1][i - 2] + stair[i];
		}

	}

	if (dp[0][N] > dp[1][N]) {
		printf("%d", dp[0][N]);
	}
	else {
		printf("%d", dp[1][N]);
	}

}




int main() {
    
	scanf("%d", &N);
    
	for (int i = 1; i <= N; i++) {
		scanf("%d", &stair[i]);
	}

	up();
    
	return 0;
}