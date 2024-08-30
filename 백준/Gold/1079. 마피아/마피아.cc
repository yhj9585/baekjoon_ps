#include <stdio.h>

int N;
int R[17][17] = { 0, };
int participant[17] = { 0, };
int mafiaN = 0;

int partchk[17] = { 0, };

int leftPeople = 0;

int longest = 0;

void simul(int time) {
	if (leftPeople % 2 == 0) { // NIGHT
		for (int i = 0; i < N; i++) {
			if (i == mafiaN) {
				continue;
			}
			if (partchk[i] == 0) {
				partchk[i] = 1;
				leftPeople--;
				for (int j = 0; j < N; j++) {
					participant[j] += R[i][j];
				}
				simul(time+1);
				leftPeople++;
				for (int j = 0; j < N; j++) {
					participant[j] -= R[i][j];
				}
				partchk[i] = 0;
			}
		}
	}
	else {					   // MORNING
		int guiltyMan = 16;
		int guilty = 0;
		for (int i = 0; i < N; i++) {
			if (partchk[i] == 1) {
				continue;
			}
			else {
				if (participant[i] > guilty) {
					guiltyMan = i;
					guilty = participant[i];
				}
			}
		}

		if (guiltyMan == mafiaN) {
			if (time > longest) {
				longest = time;
			}
			return;
		}
		else {
			partchk[guiltyMan] = 1;
			leftPeople--;
			simul(time);
			leftPeople++;
			partchk[guiltyMan] = 0;
		}

	}
	return;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &participant[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &R[i][j]);
		}
	}
	scanf("%d", &mafiaN);

	leftPeople = N;
	simul(0);
	printf("%d\n", longest);
	return 0;
}