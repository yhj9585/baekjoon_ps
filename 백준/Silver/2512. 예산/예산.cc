#include <stdio.h>
#pragma warning (disable:4996)

int N;
int limit;
int low, high;
int sum;

int num[100006];
int S[100006];
int cnt[100006];

void higher() {

	int left = low;
	int right = high;
	int mid;
	int tmp = 0;

	mid = (left + right) / 2;

	while (left <= right) {

		mid = (left + right) / 2;

		if (S[mid - 1] + (N - cnt[mid - 1])*mid > limit) {
			right = mid - 1;
			if (S[right - 1] + (N - cnt[right - 1]) * right < limit) {
				mid = right;
				break;
			}
		}
		else if (S[mid - 1] + (N - cnt[mid - 1]) * mid == limit) {
			break;
		}
		else {
			left = mid + 1;
		}
	}

	if (left == right) {
		mid = right;
	}
	printf("%d", mid);

}


int main() {
	
	int a;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		num[a]++;
		
		if (a > high) {
			high = a;
		}

		if (low == 0) {
			low = a;
		}
		else if (a < low) {
			low = a;
		}
		sum += a;
	}

	scanf("%d", &limit);

	if (sum <= limit) {
		printf("%d", high);
		return 0;
	}
	else if (low * N > limit) {
		printf("%d", limit / N);
		return 0;
	}

	for (int i = low; i <= high; i++) {
		
		cnt[i] += cnt[i - 1];
		S[i] += S[i - 1];
		
		if (num[i] != 0) {
			cnt[i] += num[i];
			S[i] += i *num[i];
		}
	}

	higher();



}