#include <stdio.h>

int N; int M;

long long arr[100001] = { 0, };
long long tree[400001] = { 0, };

long long init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	long long bef;
	long long aft;

	bef = init(start, (start + end) / 2, node * 2);
	aft = init((start + end) / 2 + 1, end, node * 2 + 1);
	if (bef < aft) {
		return tree[node] = bef;
	}
	else {
		return tree[node] = aft;
	}
}

long long smallest = 1987654321;
long long find(int start, int end, int node, int left, int right) {
	if (left > end || right < start) {
		return 1987654321;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}

	long long bef; long long aft;
	bef = find(start, (start + end) / 2, node * 2, left, right);
	aft = find((start + end) / 2 + 1, end, node * 2 + 1, left, right);
	if (bef < aft) {
		return bef;
	}
	else {
		return aft;
	}
	
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	init(0, N - 1, 1);
	int bef; int aft;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &bef, &aft);
		printf("%lld\n", find(0, N - 1, 1, bef-1, aft-1));
	}


	return 0;
}