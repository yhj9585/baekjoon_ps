#pragma warning (disable:4996)

#include <iostream>
#include <cstring>

using namespace std;

// 200 000 >> 800 000

int arr[100010] = { 0, };
int tree[800100] = { 0, };

int TC;
int N;
int M;

int maketree(int pos, int st, int ed, int cut) {
	if (st > cut) {
		return 0;
	}

	if (st == ed) {
		return tree[pos] = 1;
	}

	int mid = (st + ed) / 2;

	int bef = maketree(pos * 2, st, mid, cut);
	int aft = maketree(pos * 2 + 1, mid + 1, ed, cut);

	return tree[pos] = bef + aft;
}

void updatetree(int pos, int st, int ed, int change, int value) {
	if (st > change || change > ed) {
		return;
	}

	if (st == ed) {
		tree[pos] += value;
		return;
	}

	int mid = (st + ed) / 2;

	updatetree(pos * 2, st, mid, change, value);
	updatetree(pos * 2 + 1, mid + 1, ed, change, value);

	tree[pos] += value;

	return;
}

int query(int pos, int st, int ed, int qst, int qed) {
	if (st >= qst && ed <= qed) {
		return tree[pos];
	}

	if (qst > ed || qed < st) {
		return 0;
	}

	int mid = (st + ed) / 2;

	int bef = query(pos * 2, st, mid, qst, qed);
	int aft = query(pos * 2 + 1, mid + 1, ed, qst, qed);

	return bef + aft;
}

int main() {
	//freopen("input.txt", "r", stdin);

	scanf("%d", &TC);

	int nowdvd;
	int nowpos;
	int nowtop;

	int largest = 0;

	int temp = 0;
	for (int t = 0; t < TC; t++) {
		scanf("%d %d", &N, &M);

		memset(arr, 0, sizeof arr);
		memset(tree, 0, sizeof tree);
		nowtop = N;

		int largest = N + M + 1;

		for (int i = 1; i <= N; i++) {
			arr[i] = N-i+1;
		}

		maketree(1, 1, largest, N);

		for (int i = 0; i < M; i++) {
			scanf("%d", &nowdvd);

			nowpos = arr[nowdvd];

			temp = query(1, 1, largest, nowpos, nowtop);
			printf("%d ", temp-1);

			updatetree(1, 1, largest, nowpos, -1);
			
			arr[nowdvd] = nowtop + 1;
			updatetree(1, 1, largest, nowtop + 1, 1);

			nowtop++;
		}
		printf("\n");
	}

	return 0;
}