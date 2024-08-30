#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)



typedef struct node
{
	int* data;
	struct node* next;

} queue_node;

typedef struct
{
	queue_node* head;
	queue_node* tail;
	int count;


} queue;

queue* newQueue() {
	queue* newQueue = (queue*)malloc(sizeof(queue));

	newQueue->head = NULL;
	newQueue->tail = NULL;
	newQueue->count = 0;

	return newQueue;
}



void push(queue* queue, int* ndata) {
	queue_node* newNode = (queue_node*)malloc(sizeof(queue));
	newNode->data = ndata;
	newNode->next = NULL;


	if (queue->count == 0) {
		queue->head = newNode;
		queue->tail = newNode;
		(queue->count)++;
	}
	else if (queue->count >= 1) {
		queue->tail->next = newNode;
		queue->tail = newNode;
		(queue->count)++;
	}


}

void pop(queue* queue) {
	queue_node* delnode;

	if (queue->count == 0) {
		printf("-1\n");
		return;
	}
	
	delnode = queue->head;

	printf("%d\n", *(queue->head->data));
	
	if (queue->count == 1) {
		queue->tail = NULL;
		queue->head = NULL; 
	}
	else {
		queue-> head = queue->head->next;
	}
	

	(queue->count)--;

	free(delnode);
}

void size(queue* queue) {
	printf("%d\n", queue->count);
}

void empty(queue* queue) {
	if (queue->count == 0) {
		printf("%d\n", 1);
	}
	else {
		printf("%d\n", 0);
	}
}

void front(queue* queue) {
	if (queue->count == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", *(queue->head->data));
	}


}

void back(queue* queue) {
	if (queue->count == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", *(queue->tail->data));
	}

}

int main() {

	int func;
	char funcName[10];
	char cpush [] = { "push" };
	char cpop  [] = { "pop" };
	char csize [] = { "size" };
	char cempty[] = { "empty" };
	char cfront[] = { "front" };
	char cback [] = { "back" };

	queue* myQueue = newQueue();

	scanf("%d", &func);


	for (int i = 0; i < func; i++) {
		scanf("%s", funcName);
		//printf("%s", funcName);


		if (strcmp(funcName, cpush) == 0) {



			int* newdata = (int*)malloc(sizeof(int));

			scanf("%d", newdata);
			push(myQueue, newdata);
		}
		else if (strcmp(funcName, cpop) == 0) {
			pop(myQueue);
		}
		else if (strcmp(funcName, csize) == 0) {
			size(myQueue);
		}
		else if (strcmp(funcName, cempty) == 0) {
			empty(myQueue);
		}
		else if (strcmp(funcName, cfront) == 0) {
			front(myQueue);
		}
		else if (strcmp(funcName, cback) == 0) {
			back(myQueue);
		}

	}






	return 0;
}
