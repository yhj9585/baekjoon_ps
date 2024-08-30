#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct node;
struct line;

int N, M, V;
node* node_list[1005];

struct node {
	int data;
	line* arr_L;
	int dfs, bfs;
}NODE;

struct line {
	node* pre;
	node* nxt;
	line* nxt_L;
}LINE;


node* queue[1005];
int st, ed;

void q_push(node* n) {
	queue[ed++] = n;
	return;
}
node* q_pop() {
	return queue[st++];
}
int q_size() {
	return ed - st;
}


void bfs(node* n_node) {

	q_push(n_node);
	n_node->bfs = 1;

	node* nowptr;
	line* n_line;
	while (q_size() != 0) {
		nowptr = q_pop();
		n_line = nowptr->arr_L;

		printf("%d ", nowptr->data);

		while (n_line != NULL) {

			if (n_line->nxt->bfs == 0) {
				q_push(n_line->nxt);
				n_line->nxt->bfs = 1;
			}
			n_line = n_line->nxt_L;
		}

	}


}


void dfs(node* n_node) {
	n_node->dfs = 1;
	printf("%d ", n_node->data);

	line* n_line;
	n_line = n_node->arr_L;

	while (n_line != NULL) {

		if (n_line->nxt->dfs == 0) {
			dfs(n_line->nxt);
		}


		n_line = n_line->nxt_L;

	}

}



void newLine(line* new_line, int pre, int nxt) {

	if (node_list[pre]->arr_L == NULL) {
		node_list[pre]->arr_L = new_line;
	}
	else {

		line* nowptr = node_list[pre]->arr_L;
		line* preptr = NULL;

		// 간선 정렬
		while (1) {


			if (nowptr->nxt->data > new_line->nxt->data) {
				if (preptr == NULL) {
					node_list[pre]->arr_L = new_line;
					new_line->nxt_L = nowptr;
				}
				else {
					preptr->nxt_L = new_line;
					new_line->nxt_L = nowptr;
				}
				break;
			}
			else {

				if (nowptr->nxt_L != NULL) {
					preptr = nowptr;
					nowptr = nowptr->nxt_L;
				}
				else {
					nowptr->nxt_L = new_line;
					break;
				}
			}
		}
	}
}




int main() {

	scanf("%d %d %d", &N, &M, &V);


	// 노드 추가
	node* new_node;
	for (int i = 1; i <= N; i++) {

		new_node = (node*)malloc(sizeof(node));
		new_node->data = i;
		new_node->arr_L = NULL;
		new_node->bfs = 0;
		new_node->dfs = 0;

		node_list[i] = new_node;

	}


	// 간선 추가
	int pre, nxt;
	line* new_line;
	for (int i = 0; i < M; i++) {

		scanf("%d %d", &pre, &nxt);

		new_line = (line*)malloc(sizeof(line));
		new_line->pre = node_list[pre];
		new_line->nxt = node_list[nxt];
		new_line->nxt_L = NULL;
		newLine(new_line, pre, nxt);

		new_line = (line*)malloc(sizeof(line));
		new_line->pre = node_list[nxt];
		new_line->nxt = node_list[pre];
		new_line->nxt_L = NULL;
		newLine(new_line, nxt, pre);

	}

	dfs(node_list[V]);
	printf("\n");
	bfs(node_list[V]);



}