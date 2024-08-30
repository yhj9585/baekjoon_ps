#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996) 

char len[1000005];
char boom[40];



// stack
struct node {
	node* pre;
	node* nxt;
	char* data;
};

struct stack{
	node* head;
	node* tail;
	int count;
};



stack stk;

node* newNode(char* data) {

	node* nNode;
	nNode = (node*)malloc(sizeof(node));

	nNode->data = data;
	nNode->pre = NULL;
	nNode->nxt = NULL;

	return nNode;

}


void push(node* n, stack* stk) {

	if (stk->count == 0) {
		stk->head = n;
		stk->tail = n;
		stk->count++;
	}
	else {
		stk->tail->nxt = n;
		n->pre = stk->tail;
		stk->tail = n;
		stk->count++;
	}

}

void printlen(stack* stk);


void booming(stack* stk, node* st, node* ed, int boomlen) {

	stk->count -= boomlen;
	
	if (stk->head == stk->tail) {
		stk->head == NULL;
		stk->tail == NULL;
		return;
	}
	
	if (st == stk->head) {
		stk->head = ed->nxt;
		return;
	}
	else if (ed == stk->tail) {
		stk->tail = st->pre;
		return;
	}


	st->pre->nxt = ed->nxt;
	ed->nxt->pre = st->pre;


	return;

}

void check(stack* stk, int boomlen) {

	int nBoom = 0;

	int* bmchk = (int*) malloc(sizeof(int) * ((stk->count)+10) );
	node** boomStpt = (node**)malloc(sizeof(node) * ((stk->count)+10) );

	node* nptr = NULL;

	nptr = stk->head;

	do {
		int jump = 0;
		if (nptr == stk->tail) {
			jump = 1;
		}

		if (*(nptr->data) == boom[0]) {
			boomStpt[++nBoom] = nptr;
			bmchk[nBoom] = 1;
		}
		else if (nBoom != 0 && *(nptr->data) == boom[bmchk[nBoom]]) {
			bmchk[nBoom]++;
		}
		else {
			//bmchk[nBoom] = 0;
			nBoom = 0;
		}

		// boom
		if (bmchk[nBoom] == boomlen) {


			booming(stk, boomStpt[nBoom], nptr, boomlen);
			bmchk[nBoom] = 0;
			nBoom--;

			if (stk->count == 0) {
				break;
			}

			//printlen(stk);
		}

		if (jump == 1) {
			break;
		}

		nptr = nptr->nxt;

	} while (1);

	free(bmchk);
	free(boomStpt);
}

void printlen(stack* stk) {

	if (stk->count == 0) {
		printf("FRULA\n");
		return;
	}

	node* nptr;
	nptr = stk->head;

	while (nptr != stk->tail) {

		printf("%c", *(nptr->data));


		nptr = nptr->nxt;
	}
	printf("%c", *(nptr->data));

	printf("\n");

}

int main() {

	scanf("%s", &len);
	getchar();
	scanf("%s", &boom);

	stack stk;
	stk.count = 0;
	stk.head = NULL;
	stk.tail = NULL;
	
	int length = strlen(len);
	int boomlen = strlen(boom);

	node* nNode;

	for (int i = 0; i < length; i++) {
		nNode = newNode(len + i);
		push(nNode, &stk);
	}
	
	check(&stk, boomlen);
	printlen(&stk);

	return 0;
}