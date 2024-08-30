#include <stdio.h>
#include <stdlib.h>

int N; 
int M; int K;

long long* arr;
long long* tree;

long long init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, long long left, long long right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(start, (start + end) / 2, node * 2, left, right) + sum((start + end) / 2 + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long diff) {
	if (index < start || index > end) {
		return;
	}
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(start, (start + end) / 2, node * 2, index, diff);
		update((start + end) / 2 + 1, end, node * 2 + 1, index, diff);
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	tree = (long long*)malloc(4 * (N+1) * sizeof(long long));
	arr = (long long*)malloc((N+1) * sizeof(long long));

	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	init(0, N - 1, 1);

	int type;
	long long bef; long long aft;
	for (int i = 0; i < M + K; i++) {
		scanf("%d %lld %lld", &type, &bef, &aft);
		if (type == 1) {
			long long diff = aft - arr[bef-1];
			arr[bef-1] = aft;
			update(0, N - 1, 1, bef-1, diff);
		}
		else {
			printf("%lld\n", sum(0, N - 1, 1, bef - 1, aft - 1));
		}
	}


	return 0;
}