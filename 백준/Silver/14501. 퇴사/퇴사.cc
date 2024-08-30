#include <stdio.h>
#pragma warning(disable:4996)

int N;

int large;

int nxt[30];
int value[30];

int result[30];

void larger(int i, int val) {

	if (val > result[i]) {
		result[i] = val;
	}

	return;
}

void dp(int now, int from) {

	int nowV;

	for (int i = from; i <= N; i++) {
		
		if (i + nxt[i] > N+1) {
			continue;
		}

		nowV = value[i] + result[now];
		larger(i, nowV);
		
			

		dp(i, nxt[i]+i);

	}

	return;

}

void fin() {

	for (int i = 1; i <= N; i++) {

		if (result[i] > large) {
			large = result[i];
		}
	}

	printf("%d", large);

}

int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &nxt[i], &value[i]);
	}


	dp(0, 1) ;

	fin();

}
