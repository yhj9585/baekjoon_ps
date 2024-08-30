#include <stdio.h>

int N; int M;
int map[1001][1001] = {0,};
int chk[1001][1001] = {0,};

int move[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
};

typedef struct pos {
    int y;
    int x;
    int depth;
}pos;

int st = 0; int ed = 0;
pos queue[1000005] = {0,};
void push(pos node) {
    queue[st++] = node;
    return;
}
pos pop() {
    return queue[ed++];
}
int size() {
    return st-ed;
}

void pri() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1 && chk[i][j] == 0) {
                printf("-1 ");
            }
            else {
                printf("%d ", chk[i][j]);
            }
        }
        printf("\n");
    }
}

int check(pos nxtpos) {
    if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= M || nxtpos.x < 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 2) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 1 && chk[nxtpos.y][nxtpos.x] == 0) {
        return 1;
    }
    return 0;
}

void bfs() {
    pos nowpos;
    pos nxtpos;


    while(size() != 0) {
        nowpos = pop();
        for (int i = 0; i < 4; i++) {
            nxtpos.y = nowpos.y + move[i][0];
            nxtpos.x = nowpos.x + move[i][1];
            nxtpos.depth = nowpos.depth + 1;
            if (check(nxtpos) == 1) {
                push(nxtpos);
                chk[nxtpos.y][nxtpos.x] = nxtpos.depth;
            }
            else {
                continue;
            }
        
        }

    }






    return;
}

int main() {
    pos newpos;
    newpos.depth = 0;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                newpos.y = i;
                newpos.x = j;
                push(newpos);
            }
        }
    }

    bfs();

    pri();

    return 0;
}