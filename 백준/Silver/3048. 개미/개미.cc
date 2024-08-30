#include <stdio.h>
#pragma warning(disable:4996)

int N1, N2;
int time;

char ants[30] = { 0, };
int  dir[30];
int  chk[30];


void go(int time) {

	char temp;

	for (int t = 1; t <= time; t++) {
		for (int i = 1; i < N1 + N2; i++) {
				if (dir[i] == 1 && dir[i + 1] == -1 && chk[i] != t) {

					temp = ants[i];
					ants[i] = ants[i + 1];
					ants[i + 1] = temp;

					dir[i] = -1;
					dir[i + 1] = 1;

					chk[i] = t;
					chk[i + 1] = t;
				}


		}
		
	}

	for (int i = 1; i <= N1 + N2; i++) {
		printf("%c", ants[i]);
	}

}


int main() {
	ants[0] = 't';

	scanf("%d %d", &N1, &N2);

	getchar();
	for (int i = N1; i > 0; i--) {
		scanf("%1c", &ants[i]);
		dir[i] = 1;
	}

	getchar();
	for (int i = N1 + 1; i <= N1+N2; i++) {
		scanf("%1c", &ants[i]);
		dir[i] = -1;
	}

	scanf("%d", &time);

	go(time);

	return 0;
}