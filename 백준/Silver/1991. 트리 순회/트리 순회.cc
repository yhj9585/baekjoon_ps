#pragma warning (disable:4996)

#include <iostream>

typedef struct node {
	char data;
	int left;
	int right;
}node;

using namespace std;

int N;
node tree[60] = { 0, };

void pretrav(int pos) {
	printf("%c", tree[pos].data);

	if (tree[pos].left != -1) {
		pretrav(tree[pos].left);
	}

	if (tree[pos].right != -1) {
		pretrav(tree[pos].right);
	}

	return;
}
void midtrav(int pos) {
	if (tree[pos].left != -1) {
		midtrav(tree[pos].left);
	}

	printf("%c", tree[pos].data);

	if (tree[pos].right != -1) {
		midtrav(tree[pos].right);
	}

	return;
}
void posttrav(int pos) {
	if (tree[pos].left != -1) {
		posttrav(tree[pos].left);
	}

	if (tree[pos].right != -1) {
		posttrav(tree[pos].right);
	}

	printf("%c", tree[pos].data);

	return;
}

int main() {
	scanf("%d", &N);

	

	getchar();
	char input; char left; char right;
	for (int i = 0; i < N; i++) {
		scanf("%1c %1c %1c", &input, &left, &right);

		tree[input - 'A'].data = input;

		if (left == '.') {
			tree[input - 'A'].left = -1;
		}
		else {
			tree[input - 'A'].left = left - 'A';
		}

		if (right == '.') {
			tree[input - 'A'].right = -1;
		}
		else {
			tree[input - 'A'].right = right - 'A';
		}

		getchar();
	}

	pretrav(0);
	printf("\n");
	midtrav(0);
	printf("\n");
	posttrav(0);
	printf("\n");



	return 0;
}