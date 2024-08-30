#include <stdio.h>
#include <stdlib.h>

int N = 0;
int M = 0;

int chk[2000] = { 0, };
int relation[2000] = { 0, };

typedef struct link {
	struct link* nxt;
	int goesTo;
}link;

link* list[2000] = { 0, };

int success = 0;

void simul(int time, int nowpos) {
	if (success == 1) {
		return;
	}
	if (time == 5) {
		printf("1\n");
		success = 1;
		return;
	}


	link* nowlink = 0;
	nowlink = list[nowpos];

	for (int j = 0; j < relation[nowpos]; j++) {
		if (chk[nowlink->goesTo] == 0) {
			chk[nowlink->goesTo] = 1;
			simul(time + 1, nowlink->goesTo);
			chk[nowlink->goesTo] = 0;
		}

		if (nowlink->nxt != 0) {
			nowlink = nowlink->nxt;
		}
		else {
			break;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	int pre = 0; int nxt = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &pre, &nxt);
		relation[pre]++;
		relation[nxt]++;

		link* prenew = (link*)malloc(sizeof(link));
		prenew->goesTo = nxt;
		prenew->nxt = list[pre];
		list[pre] = prenew;

		link* nxtnew = (link*)malloc(sizeof(link));
		nxtnew->goesTo = pre;
		nxtnew->nxt = list[nxt];
		list[nxt] = nxtnew;
	}

	int nowpos = 0;
	link* nowlink = 0;
	for (int i = 0; i < N; i++) {
		//push(i);
		chk[i] = 1;
		simul(1, i);
		chk[i] = 0;

		if (success == 1) {
			break;
		}

	}
	if (success == 0) {
		printf("0\n");
	}
	return 0;
}

