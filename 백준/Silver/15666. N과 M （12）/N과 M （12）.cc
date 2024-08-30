#include <stdio.h>
#pragma warning (disable : 4996)

#define SIZE 10005

int s[SIZE];
int tp;
int arr[SIZE];

// stack //
void push(int n) {
	s[tp++] = n;
}

void pop() {
	tp = tp - 1;
}

int size() {
	return tp;
}

void printStack() {
	for (int i = 0; i < tp; i++) {
		printf("%d ", arr[s[i]]);
	}
	printf("\n");
}


int N, M;
int visit[SIZE];
int before[SIZE];

void num(int t, int a) {
	//(1)
	//if (visit[a] == 1 || arr[a] == before[t]) return;
	if (arr[a] == before[t]) return;
	push(a);
	visit[a] = 1;

	if (size() != M) {
		//for (int n = 1; n <= N; n++) {
		//for (int n = a+1; n <= N; n++) {
		for (int n = a; n <= N; n++) {		
			num(t + 1, n);
		}
	}

	if (size() == M) {
		printStack();
	}

	for (int i = 1; i <= N; i++) {
		before[i] = 0;
	}


	//visit[a] = 0;
	pop();
	before[t] = arr[a];
}

int temp;

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (arr[i] == arr[i - 1]) {
			continue;
		}
		num(1, i);
	
	}

}