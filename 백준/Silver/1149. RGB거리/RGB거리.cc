#include <stdio.h>
#pragma warning(disable:4996) 

int N;

int color[3][1010] = { 0, };
int dp[3][1010] = { 0, };

void paint() {

	dp[0][1] = color[0][1];
	dp[1][1] = color[1][1];
	dp[2][1] = color[2][1];

	for (int i = 2; i <= N; i++) {

		// dp[0][i]
		if (dp[1][i - 1] < dp[2][i - 1]) {
			dp[0][i] = color[0][i] + dp[1][i - 1];
		}
		else {
			dp[0][i] = color[0][i] + dp[2][i - 1];
		}

		// dp[1][i]
		if (dp[0][i - 1] < dp[2][i - 1]) {
			dp[1][i] = color[1][i] + dp[0][i - 1];
		}
		else {
			dp[1][i] = color[1][i] + dp[2][i - 1];
		}

		// dp[2][i]
		if (dp[0][i - 1] < dp[1][i - 1]) {
			dp[2][i] = color[2][i] + dp[0][i - 1];
		}
		else {
			dp[2][i] = color[2][i] + dp[1][i - 1];
		}
	}


	if (dp[0][N] < dp[1][N]) {
		if (dp[0][N] < dp[2][N]) {
			printf("%d ", dp[0][N]);
		}
		else {
			printf("%d ", dp[2][N]);
		}
	}
	else {
		if (dp[1][N] < dp[2][N]) {
			printf("%d ", dp[1][N]);
		}
		else {
			printf("%d ", dp[2][N]);
		}
	}
}



int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &color[j][i]);
		}
	}

	paint();


	return 0;
}
