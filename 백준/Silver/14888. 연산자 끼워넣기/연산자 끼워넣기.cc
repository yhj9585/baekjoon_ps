#include <stdio.h>
#pragma warning (disable: 4996)

int N;
int cal[5];
int num[1000] = { 0, };


int top;
int stack[1000];

int arr_c[1000];
int visit[1000] = { 0, };


void push(int c) {
	stack[top++] = c;
}
int pop() {
	return stack[--top];
	
}
int size() {
	return top;
}
int calculate() {

	int answer = num[0];

	for (int i = 0; i < N - 1; i++) {
		if (arr_c[stack[i]] == 1) {
			answer += num[i + 1];
		}
		else if (arr_c[stack[i]] == 2) {
			answer -= num[i + 1];
		}
		else if (arr_c[stack[i]] == 3) {
			answer *= num[i + 1];
		}
		else if (arr_c[stack[i]] == 4) {
			answer /= num[i + 1];
		}
	}

	return answer;
}

// TEST //
void printer() {
	for (int i = 0; i < N - 1; i++) {
		printf("%d", stack[i]);
	}
	printf("\n");
}




int large, small;
int first;

// DFS // 
void dfs(int n) {
	push(n);
	visit[n] = 1;

	for (int i = 0; i < N - 1; i++) {
		if (visit[i] == 0 && arr_c[i] != 0) {
			dfs(i);
		}
	}
	
	
	if (size() == N - 1) {
		int answer = calculate();
		//printer();
		if (first == 0) {
			large = answer;
			small = answer;
			first = 1;
		}
		else {
			if (large < answer) {
				large = answer;
			}
			if (small > answer) {
				small = answer;
			}
		}
	}


	int a = pop();
	visit[a]= 0;



	
}





int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 1; i <= 4; i++) {
		scanf("%d", &cal[i]);
	}


	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j <= 4; j++) {
			if (cal[j] != 0) {
				arr_c[i] = j;
				cal[j]--;
				break;

			}

		}
	}
	for (int a = 0; a < N - 1; a++) {
		dfs(a);
	}

	printf("%d\n%d", large, small);
	
	return 0;

}