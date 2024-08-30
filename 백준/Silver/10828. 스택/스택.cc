#include <stdio.h>
#include <string.h>

#pragma warning (disable :4996)

int stack[1000000];
int tp;

void push(int n) {
	stack[tp++] = n;
	return;
}

void pop() {
	if (tp != 0) {
		printf("%d\n", stack[--tp]);
	}
	else {
		printf("-1\n");
	}
	return;
}

void top() {
	if (tp != 0) {
		printf("%d\n", stack[tp - 1]);
	}
	else {
		printf("-1\n");
	}
	return;
}

int main() {
	int N;
	scanf("%d", &N);

	getchar();

	char input[10];
	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		

		if (!strcmp(input, "push")) {
			int x;
			scanf("%d", &x);
			getchar();

			push(x);
		}
		else if (!strcmp(input, "pop")) {
			pop();
		}
		else if (!strcmp(input, "top")) {
			top();
		}
		else if (!strcmp(input, "size")) {
			printf("%d\n", tp);
		}
		else if (!strcmp(input, "empty")) {
			if (tp == 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}

		}
	}
	return 0;
}