#include <stdio.h>

int N; int M; int breakable;
int map[1003][1003] = {0,};
//int chk[2][1003][1003] = {0,};
int brokenchk[1003][1003] = {0,};
const int NOTGO = 20;

int move[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1} 
};

typedef struct pos {
    int y;
    int x;
    int broken;
    int depth;
}pos;

int st = 0; int ed = 0;
pos queue[12000000] = {0,};
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


int check(pos nxtpos) {
    if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= M || nxtpos.x < 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 0 && brokenchk[nxtpos.y][nxtpos.x] > nxtpos.broken) {
        return 1;
    }
    else if (map[nxtpos.y][nxtpos.x] == 1 && brokenchk[nxtpos.y][nxtpos.x] > nxtpos.broken+1) {
        if (nxtpos.broken == breakable) {
            return 0;
        }
        return 2;
    }
    
    return 0;
}
/*
void pri() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d/%d ", chk[0][i][j], chk[1][i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%2d/%2d ", brokenchk[0][i][j], brokenchk[1][i][j]);
        }
        printf("\n");
    }
    return;
}
*/

void bfs() {
    pos nowpos;
    pos nxtpos;
    while (size() != 0) {
        nowpos = pop();
        //printf("[%d,%d] Depth : %d\n", nowpos.y, nowpos.x, nowpos.depth);
        //pri();

        
        if (nowpos.y == N-1 && nowpos.x == M-1) {
            //pri();
            printf("%d\n", nowpos.depth);
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            nxtpos.y = nowpos.y + move[i][0];
            nxtpos.x = nowpos.x + move[i][1];
            nxtpos.depth = nowpos.depth + 1;
            nxtpos.broken = nowpos.broken;
            if (check(nxtpos) == 1) {
                //chk[(day+1)%2][nxtpos.y][nxtpos.x] = nxtpos.depth;
                brokenchk[nxtpos.y][nxtpos.x] = nxtpos.broken;
                push(nxtpos);

                if (nxtpos.y == N-1 && nxtpos.x == M-1) {
                    //pri();
                    printf("%d\n", nxtpos.depth);
                    return;
                }
            }
            else if (check(nxtpos) == 2) {
                //chk[(day+1)%2][nxtpos.y][nxtpos.x] = nxtpos.depth;
                nxtpos.broken = nxtpos.broken+1;
                brokenchk[nxtpos.y][nxtpos.x] = nxtpos.broken;
                push(nxtpos);
            }
        }
        if (/*chk[(day+1)%2][nowpos.y][nowpos.x] == 0 && */brokenchk[nowpos.y][nowpos.x] > nowpos.broken) {
            nxtpos.y = nowpos.y;
            nxtpos.x = nowpos.x;
            nxtpos.depth = nowpos.depth + 1;
            nxtpos.broken = nowpos.broken;
            //chk[(day+1)%2][nxtpos.y][nxtpos.x] = nxtpos.depth;
            brokenchk[nowpos.y][nowpos.x] = nxtpos.broken;
            push(nxtpos);
        }
    }

    printf("-1\n");

    return;
}


int main() {
    scanf("%d %d %d", &N, &M, &breakable);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
            brokenchk[i][j] = NOTGO;
        }
    }

    pos newpos;
    newpos.y = 0;
    newpos.x = 0;
    newpos.broken = 0;
    newpos.depth = 1;
    //chk[1][0][0] = 1;
    brokenchk[0][0] = 0;
    push(newpos);

    bfs();

    return 0;

}