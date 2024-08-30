#include <stdio.h>
#pragma warning (disable : 4996)

#define SIZE 10005

int s[SIZE];

int tp;

// stack //
void push(int n) {
	s[tp++] = n;
}

void pop() {
	tp--;
}

int top() {
	return s[tp];
}

int size() {
	return tp;
}

void printStack() {
	for (int i = 0; i < tp; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");
}


void cleanStack() {
	while (size() != 0) {
		pop();
	}
}

int N, M;
//int visit[SIZE];
int round;

int arr[SIZE];



void num(int t, int a) {
	//(1)
	//if (visit[arr[a]] == 1) return;
	push(arr[a]);

	//visit[arr[a]] = 1;


	if (size() != M) {

		for (int n = 1; n <= N; n++) {
		//for (int n = a+1; n <= N; n++) {
		//for (int n = a; n <= N; n++) {

			num(t + 1, n);
		}
	}

	if (size() == M) {
		printStack();
	}
	//visit[arr[a]] = 0;
	pop();
}

int temp;

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}


	/*
	printf("\n");


	for (int i = 1; i <= N; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n\n");
	*/


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	/*
	for (int i = 1; i <= N; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n\n");
	*/

	for (int i = 1; i <= N; i++) {
		num(1, i);
	}

}