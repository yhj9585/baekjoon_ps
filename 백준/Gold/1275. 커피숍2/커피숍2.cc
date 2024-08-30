#include <stdio.h>
#pragma warning(disable:4996)

int N = 0; int Q = 0;
long long inputmap[200000] = { 0, };
long long tree[500000] = { 0, };

long long maketree(int start, int end, int node) {
	int mid = (start + end) / 2;

	if (start == end) {
		return tree[node] = inputmap[start];
	}
	
	return tree[node] = maketree(start, mid, node * 2) + maketree(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	int mid = (start + end) / 2;

	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

long long addnum(int start, int end, int node, int index, long long add) {
	int mid = (start + end) / 2;

	if (index < start || index> end) {
		return 0;
	}

	tree[node] += add;
	if (start == end) {
		return 0;
	}
	addnum(start, mid, node * 2, index, add);
	addnum(mid + 1, end, node * 2 + 1, index, add);
	return 0;
}

int main() {
	scanf("%d %d", &N, &Q);


	for (int i = 1; i <= N; i++) {
		scanf("%lld", &inputmap[i]);
	}

	maketree(1, N, 1);

	long long tmp = 0; long long var = 0;
	int x = 0; int y = 0;
	long long a = 0; long long b = 0;
	for (int time = 0; time < Q; time++) {
		scanf("%d %d %lld %lld", &x, &y, &a, &b);

		if (y < x) {
			tmp = y;
			y = x;
			x = tmp;
		}

		printf("%lld\n", sum(1, N, 1, x, y));

		var = b - inputmap[a];
		inputmap[a] = b;
		addnum(1, N, 1, a, var);

	}



	return 0;
}