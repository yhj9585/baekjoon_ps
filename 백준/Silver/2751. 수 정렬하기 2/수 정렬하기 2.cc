#include <stdio.h>
#pragma warning(disable:4996)

int N;
int num[1000005];
int sorted[1000005];

/*
void quickSort(int left,int right) {

	int key = num[(left + right) / 2];
	int tmp;

	if (left < right) {

		int st = left - 1;
		int ed = right + 1;

		while (1) {

			while (num[++st] < key);
			while (num[--ed] > key);

			if (ed <= st) {
				break;
			}

			tmp = num[st];
			num[st] = num[ed];
			num[ed] = tmp;

		}

		quickSort(left, st - 1);
		quickSort(ed + 1, right);
	}
}
*/

void merge(int arr[], int st, int mid, int ed) {

	int n = 0;

	int ptr1 = st;
	int ptr2 = mid + 1;
	while (ptr1 <= mid && ptr2 <= ed) {
		if (arr[ptr1] < arr[ptr2]) {
			sorted[n++] = arr[ptr1++];
		}
		else {
			sorted[n++] = arr[ptr2++];
		}
	}

	while (ptr1 <= mid) {
		sorted[n++] = arr[ptr1++];
	}
	while (ptr2 <= ed) {
		sorted[n++] = arr[ptr2++];
	}

	for (int i = 0; i < n; i++) {
		arr[st + i] = sorted[i];
	}


}

void mergeSort(int arr[], int st, int ed) {

	int mid;
	
	if (st < ed) {
		mid = (st + ed) / 2;
		mergeSort(arr, st, mid);
		mergeSort(arr, mid + 1, ed);
		merge(arr, st, mid, ed);
	}

}





int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	//quickSort(0, N - 1);
	mergeSort(num, 0, N-1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}
	return 0;
}