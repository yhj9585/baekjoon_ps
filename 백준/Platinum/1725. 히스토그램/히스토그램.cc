#include <stdio.h>

int N; 

long long arr[100001] = { 0, };
long long tree[500001] = { 0, };
long long height[100001] = { 0, };

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

long long find(int start, int end, int node) {
	long long bef; long long aft; long long now;
	if (start == end) {
		return tree[node];
	}
	
	int mid = (start + end) / 2;
	bef = find(start, mid, node * 2);
	aft = find(mid + 1, end, node * 2 + 1);

	if (end - start == 1) {
		mid = tree[node] * 2;
		if (mid >= aft && mid >= bef) {
			return mid;
		}
		else if (bef >= mid && bef >= aft) {
			return bef;
		}
		else {
			return aft;
		}
	}

	long long midsq = 0;
	long long nowsq = 0;

	if (bef > aft) {
		midsq = bef;
	}
	else {
		midsq = aft;
	}

	int left = mid;
	int right = mid + 1;
	long long height = 0;
	if (arr[left] < arr[right]) {
		height = arr[left];
	}
	else {
		height = arr[right];
	}
	if (midsq < 2 * height) {
		midsq = 2 * height;
	}

	while (start <= left || right <= end) {
		if ((left == start || arr[left-1] <= arr[right+1]) && right < end) {
			right++; 
			if (height > arr[right]) {
				height = arr[right];
			}
			nowsq = (right - left + 1) * height;
			if (nowsq > midsq) {
				midsq = nowsq;
			}
		}
		else if ((right == end || arr[left-1] >= arr[right+1]) && start < left) {
			left--;
			if (height > arr[left]) {
				height = arr[left];
			}
			nowsq = (right - left + 1) * height;
			if (nowsq > midsq) {
				midsq = nowsq;
			}
		}
		else {
			break;
		}
	}

	return midsq;

}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	init(0, N - 1, 1);

	long long seglarge = 0;
	seglarge = find(0, N - 1, 1);

	printf("%lld\n", seglarge);

	return 0;
}