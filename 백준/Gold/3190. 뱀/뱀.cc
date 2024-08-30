#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int N;
int K;
int map[101][101];

struct pos {
	int y, x;
};

struct node {
	pos* n;
	node* pre;
	node* nxt;
};

struct snake {
	node* head;
	node* tail;
	int dir;
};

pos move[4] = {
	{ 0, -1}, // Left  | 0
	{-1,  0}, // Up    | 1
	{ 0,  1}, // Right | 2
	{ 1,  0}  // Down  | 3
};

int nxtTest(pos* nxt) {

	if (nxt->x < 0 || nxt->y < 0 || nxt->x >= N || nxt->y >= N) {
		return 1;
	}
	else if (map[nxt->y][nxt->x] == 1) {
		return 1;
	}
	else if (map[nxt->y][nxt->x] == 7) { // Apple
		return 7;
	}
	return 0;

}

int changeDir(char turn, int dir) {

	if (turn == 'L') {
		if (dir == 0) {
			return 3;
		}
		else {
			return dir - 1;
		}
	}
	else {
		if (dir == 3) {
			return 0;
		}
		else {
			return dir + 1;
		}
	}

}

void play(snake* snake) {
	int L;     int turnT = 1;
	int t = 1; int time;
	char turn; int apple = 0;
	pos* nxt;
	node* newNode;

	scanf("%d", &L);


	scanf("%d %c", &time, &turn);
	while (1) {

		if (time + 1 == t) {
			snake->dir = changeDir(turn, snake->dir);

			if (turnT != L) {
				scanf("%d %c", &time, &turn);
				turnT++;
			}
		}

		nxt = (pos*)malloc(sizeof(pos));
		nxt->x = snake->head->n->x + move[snake->dir].x;
		nxt->y = snake->head->n->y + move[snake->dir].y;

		if (nxtTest(nxt) == 1) {
			printf("%d", t);
			return;
		}

		
	
		if (nxtTest(nxt) == 7) {
			apple = 1;
		}

		map[nxt->y][nxt->x] = 1;
		newNode = (node*)malloc(sizeof(node));
		newNode->n = nxt;
		newNode->pre = NULL;
		newNode->nxt = snake->head;
		snake->head->pre = newNode;
		snake->head = newNode;

		if (apple == 0) {
			snake->tail = snake->tail->pre;
			map[snake->tail->nxt->n->y][snake->tail->nxt->n->x];
			map[snake->tail->nxt->n->y][snake->tail->nxt->n->x] = 0;
			free(snake->tail->nxt);
			snake->tail->nxt = NULL;
		}
		else {
			
		}

		apple = 0;
		t++;
	}
}

int main() {
	scanf("%d", &N); // Size
	scanf("%d", &K); // Apple

	// Apple Input
	int a, b;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		map[a-1][b-1] = 7;
	}

	pos* p;
	p = (pos*)malloc(sizeof(pos));
	p->x = 0;
	p->y = 0;

	node* Nnode;
	Nnode = (node*)malloc(sizeof(node));
	Nnode->n = p;
	Nnode->pre = NULL;
	Nnode->nxt = NULL;

	snake* Nsnake;
	Nsnake = (snake*)malloc(sizeof(snake));
	Nsnake->dir = 2;
	Nsnake->head = Nnode;
	Nsnake->tail = Nnode;
	map[0][0] = 1;
	// new Snake

	play(Nsnake);

	return 0;
}