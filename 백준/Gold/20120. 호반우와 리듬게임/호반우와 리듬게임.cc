#pragma warning (disable:4996)
#include <stdio.h>

int N;

int note[1002] = { 0, };
long long map[1002][1002] = { 0, };
long long miss[1002][3] = { 0, };

void simul() {

	map[1][1] = note[1];		// 1 note 1 combo
	miss[1][1] = 0;				// 1 note 1 miss

	/*
	printf("\nnote %d", 1);
	printf("%5d %5d", miss[1][2], miss[1][1]);
	printf("%5d", map[1][1]);
	*/
	
	long long large = -99987321654;

	for (int i = 2; i <= N; i++) {
		large = -99987321654;
		// 1 Combo
		if (miss[i-1][1] > miss[i-1][2]) {
			map[i][1] = miss[i-1][1] + note[i];
		}
		else {
			map[i][1] = miss[i-1][2] + note[i];
		}
		
		// 1 Miss
		for (int j = 1; j <= i-1; j++) {
			if (map[i - 1][j] > large) {
				large = map[i - 1][j];
			}
		}
		miss[i][1] = large;

		// 2 Miss
		miss[i][2] = miss[i - 1][1];


		// larger Combo
		for (int j = 2; j <= i; j++) {
			map[i][j] = map[i - 1][j - 1] + note[i] * j;
		}
		
		/*
		printf("\nnote %d", i);
		printf("%5d %5d", miss[i][2], miss[i][1]);
		
		for (int j = 1; j <= i; j++) {
			printf("%5d", map[i][j]);
		}
		*/

	}


}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &note[i]);
	}

	simul();

	if (N == 1) {
		if (note[1] < 0) {
			printf("0\n");
		}
		else {
			printf("%d\n", note[1]);
		}
		return 0;
	}


	long long large = -99987654321;
	for (int i = 1; i <= N; i++) {
		if (map[N][i] > large) {
			large = map[N][i];
		}
	}

	if (miss[N][1] > large) {
		large = miss[N][1];
	}
	if (miss[N][2] > large) {
		large = miss[N][2];
	}

	if (N >= 3) {
		if (large < 0) {
			printf("0\n");
			return 0;
		}
		
	}
	printf("%lld\n", large);

	return 0;
}