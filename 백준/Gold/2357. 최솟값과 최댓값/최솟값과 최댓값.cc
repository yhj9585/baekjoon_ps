#include <stdio.h>

int N; int M;

long long arr[100001] = { 0, };
long long s_tree[400001] = { 0, };
long long l_tree[400001] = { 0, };

long long s_init(int start, int end, int node) {
	if (start == end) {
		return s_tree[node] = arr[start];
	}
	long long bef;
	long long aft;

	bef = s_init(start, (start + end) / 2, node * 2);
	aft = s_init((start + end) / 2 + 1, end, node * 2 + 1);
	if (bef < aft) {
		return s_tree[node] = bef;
	}
	else {
		return s_tree[node] = aft;
	}
}

long long s_find(int start, int end, int node, int left, int right) {
	if (left > end || right < start) {
		return 1987654321;
	}
	if (left <= start && end <= right) {
		return s_tree[node];
	}

	long long bef; long long aft;
	bef = s_find(start, (start + end) / 2, node * 2, left, right);
	aft = s_find((start + end) / 2 + 1, end, node * 2 + 1, left, right);
	if (bef < aft) {
		return bef;
	}
	else {
		return aft;
	}

}
long long l_init(int start, int end, int node) {
	if (start == end) {
		return l_tree[node] = arr[start];
	}
	long long bef;
	long long aft;

	bef = l_init(start, (start + end) / 2, node * 2);
	aft = l_init((start + end) / 2 + 1, end, node * 2 + 1);
	if (bef > aft) {
		return l_tree[node] = bef;
	}
	else {
		return l_tree[node] = aft;
	}
}

long long l_find(int start, int end, int node, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return l_tree[node];
	}

	long long bef; long long aft;
	bef = l_find(start, (start + end) / 2, node * 2, left, right);
	aft = l_find((start + end) / 2 + 1, end, node * 2 + 1, left, right);
	if (bef > aft) {
		return bef;
	}
	else {
		return aft;
	}

}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	s_init(0, N - 1, 1);
	l_init(0, N - 1, 1);
	int bef; int aft;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &bef, &aft);
		printf("%lld %lld\n", s_find(0, N - 1, 1, bef - 1, aft - 1), l_find(0, N - 1, 1, bef - 1, aft - 1));
	}


	return 0;
}