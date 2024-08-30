#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)
int K, N;

// queue //
struct node {
	struct node* pre;
	struct node* nxt;
	int* data;

};

struct queue {
	node* head;
	int count;
	node* tail;
};




void push(int* n, queue* nqueue) {
	node* n_node;
	n_node = (node*)malloc(sizeof(node));
	n_node->pre = NULL;
	n_node->nxt = NULL;
	n_node->data = n;

	if (nqueue->count == 0) {
		n_node->pre = n_node;
		n_node->nxt = n_node;

		nqueue->head = n_node;
		nqueue->tail = n_node;
	}
	else {
		nqueue->tail->nxt = n_node;
		n_node->pre = nqueue->tail;
		nqueue->tail = n_node;
	}
	nqueue->count++;

	nqueue->tail->nxt = nqueue->head;
	nqueue->head->pre = nqueue->tail;

	return;
}
void pop(node* node, queue* nqueue) {
	
	int* n;
	
	n = node->data;
	node->pre->nxt = node->nxt;
	node->nxt->pre = node->pre;
	nqueue->count--;

	printf("%d", *n);
}

void yose(queue* nqueue) {


	for (int i = 1; i <= N; i++) {
		int* j = (int*)malloc(sizeof(int));
		*j = i;
		push(j, nqueue);
	}

	printf("<");

	int i = 1;
	node* n = nqueue->head;
	while (nqueue->count != 1) {
		if (i % K == 0) {
			pop(n, nqueue);
			printf(", ");
		}
		n = n->nxt;
		i++;
	}

	printf("%d", *(n->data));
	printf(">");

}


int main() {
	queue* nqueue;
	nqueue = (queue*)malloc(sizeof(queue));

	nqueue->count = 0;
	nqueue->head = NULL;
	nqueue->tail = NULL;

	scanf("%d %d", &N, &K);

	yose(nqueue);

	return 0;
}
