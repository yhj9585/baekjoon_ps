#include <stdio.h>

int N;
int map[101][101] = {0,};
int chk[101][101] = {0,};

const int INF = 987654321;
int shortest = INF;

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

pos queueW[10001] = {0,};
int stW = 0; int edW = 0;
void pushW(pos nxtpos) {
    queueW[stW++] = nxtpos;
    return;
}
pos popW() {
    return queueW[edW++];
}
int sizeW() {
    return stW-edW;
}

pos queueG[10001] = {0,};
int stG = 0; int edG = 0;
void pushG(pos nxtpos) {
    queueG[stG++] = nxtpos;
    return;
}
pos popG() {
    return queueG[edG++];
}
int sizeG() {
    return stG-edG;
}

int continental = 1;


void pri() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d", chk[i][j]);
        }
        printf("\n");
    }
}

int checkG(pos nxtpos) {
    if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= N || nxtpos.x < 0) {
        return 0;
    }
    else if (chk[nxtpos.y][nxtpos.x] == continental) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 1) {
        return 1;
    }
    else if (map[nxtpos.y][nxtpos.x] == 0) {
        return 2;
    }

    return 0;
}  

int checkW(pos nxtpos) {
    if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= N || nxtpos.x < 0) {
        return 0;
    }
    else if (chk[nxtpos.y][nxtpos.x] == continental) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 1) {
        return 2;
    }
    else if (map[nxtpos.y][nxtpos.x] == 0) {
        return 1;
    }
    return 0;
}

void bfs() {
    pos nowpos;
    pos nxtpos;
    stW = 0;
    edW = 0;

    while (sizeG() != 0) {
        nowpos = popG();
        for (int i = 0; i < 4; i++) {
            nxtpos.y = nowpos.y + move[i][0];
            nxtpos.x = nowpos.x + move[i][1];
            nxtpos.depth = nowpos.depth;
            if (checkG(nxtpos) == 1) { // is CONTINENTAL
                chk[nxtpos.y][nxtpos.x] = continental;
                pushG(nxtpos);
            }
            else if (checkG(nxtpos) == 2) { // is WATER
                chk[nxtpos.y][nxtpos.x] = continental;
                nxtpos.depth = 1;
                pushW(nxtpos);
            }
            else {
                continue;
            }
        }
    }

    //printf("CONTINENTAL %d\n", continental);
    //pri();


    while(sizeW() != 0) {
        nowpos = popW();
        if (nowpos.depth > shortest) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            nxtpos.y = nowpos.y + move[i][0];
            nxtpos.x = nowpos.x + move[i][1];
            nxtpos.depth = nowpos.depth + 1;
            
            if (checkW(nxtpos) == 1) { // is WATER
                chk[nxtpos.y][nxtpos.x] = continental;
                pushW(nxtpos);
            }
            else if (checkW(nxtpos) == 2) { // is CONTINENTAL
                if (nxtpos.depth-1 < shortest) {
                    shortest = nxtpos.depth-1;
                }
            }

        }
    }

    //printf("AFTER\n");
    //pri();

    return;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    pos newpos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && chk[i][j] == 0) {
                stG = 0; edG = 0;
                newpos.y = i;
                newpos.x = j;
                newpos.depth = 0;
                chk[i][j] = continental;
                pushG(newpos);
                bfs();
                continental++;
            }
        }
    }

    printf("%d\n", shortest);


    return 0;
}