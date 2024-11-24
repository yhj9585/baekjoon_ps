#pragma warning(disable:4996)

#include <iostream>

int tree[20000];
int i;

void posttrav(int st, int ed) {
	if (st >= ed) {
		return;
	}

	for (i = st + 1; i < ed; i++) {
		if (tree[st] < tree[i]) {
			break;
		}
	}

	posttrav(st + 1, i);
	posttrav(i, ed);

	printf("%d\n", tree[st]);

	return;
}

int main() {
	int i = 0;
	int input = 0;

	while (scanf("%d", &input) != EOF) {
		tree[i] = input;
		i++;
	}

	posttrav(0, i);

	return 0;
}