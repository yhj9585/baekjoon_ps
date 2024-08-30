#include <stdio.h>

int N; int M;
int map[1001][1001] = {0,};
int chkWall[1001][1001] = {0,};
int result[1001][1001] = {0,};

int move[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
};


typedef struct pos{
    int y;
    int x;
}pos;

int st = 0; int ed = 0;
pos queue[1000001] = {0,};
void push(pos nxtpos) {
    queue[st++] = nxtpos;
    return;
}
pos pop() {
    return queue[ed++];
}
int size() {
    return st-ed;
}

int top = 0;
pos queueWall[1000001] = {0,};
void pushWall(pos nxtpos) {
    queueWall[top++] = nxtpos;
    return;
}

int emptyN = 1;

void pri() {
    printf("emptyN : %d\n", emptyN-1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //printf("emptyN : %d\n", emptyN-1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", chkWall[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", result[i][j]);
        }
        printf("\n");
    }
    return;
}

int chk(pos nxtpos) {
    if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= M || nxtpos.x < 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 1) {
        if (chkWall[nxtpos.y][nxtpos.x] != emptyN) {
            return 2;
        }
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == emptyN) {
        return 0;
    }
    else {
        return 1;
    }
}

void bfs() {
    int emptysize = 1;
    pos nowpos;
    pos nxtpos;

    while(size() != 0) {
        nowpos = pop();
        
        for (int i = 0; i < 4; i++) {
            nxtpos.y = nowpos.y + move[i][0];
            nxtpos.x = nowpos.x + move[i][1];

            if (chk(nxtpos) == 1) {
                push(nxtpos);
                map[nxtpos.y][nxtpos.x] = emptyN;
                emptysize++;
            }
            else if (chk(nxtpos) == 2) {
                chkWall[nxtpos.y][nxtpos.x] = emptyN;
                pushWall(nxtpos);
            }
        }
    }

    for (int i = 0; i < top; i++) {
        if (map[queueWall[i].y][queueWall[i].x] == 1) {
            result[queueWall[i].y][queueWall[i].x] += emptysize;
        }
    }

    return;

}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    pos newpos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                emptyN++;
                newpos.y = i;
                newpos.x = j;
                map[i][j] = emptyN;
                push(newpos);
                bfs();
                top = 0;
                st = 0; ed = 0;
                //pri();
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (result[i][j] != 0) {
                printf("%d", (result[i][j]+1)%10);
            }
            else if (map[i][j] == 1) {
                printf("1");
            }
            else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}