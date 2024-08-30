#include <stdio.h>
#include <stdlib.h>

int M; int N;
int map[102][102] = {0,};
int chk[102][102][5] = {0,};

typedef struct pos {
    int y;
    int x;
    int dir;
    int order;
}pos;

const int INF = 2000000;
int shortest = 2000000;
pos robot;
pos endpt;

int move[5][2] = {
    { 0, 0},
    { 0, 1}, // east
    { 0,-1}, // west
    { 1, 0}, // south
    {-1, 0}  // north
};

pos queue[20000] = {0,};
int st; int ed;
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


int check(pos nxtpos) {
    if (nxtpos.y > M || nxtpos.y <= 0 || nxtpos.x > N || nxtpos.x <= 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 1) {
        return 0;
    }
    else if (chk[nxtpos.y][nxtpos.x][nxtpos.dir] < nxtpos.order ) {
        return 1;
    }
    else {
        return 2;
    }
}


void bfs() {
    pos nowpos;
    pos nxtpos;

    while (size() != 0) {
        nowpos = pop();

/*
        printf("%d\n", nowpos.order-1);
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == nowpos.y && j == nowpos.x) {
                    printf("%2d", 2*nowpos.dir);
                }
                else if (map[i][j] != 1) {
                    printf(" .");
                }
                else {
                    printf(" 1");
                }
            }
            printf("\n");
        }

        printf("\n");
*/
        if (nowpos.y == endpt.y && nowpos.x == endpt.x && nowpos.dir == endpt.dir) {
            if (nowpos.order < shortest) {
                shortest = nowpos.order;
                break;
            }
        }

        for (int i = 1; i <= 4; i++) { // ROTATION
            nxtpos.y = nowpos.y;
            nxtpos.x = nowpos.x;
            nxtpos.dir = nowpos.dir;
            nxtpos.order = nowpos.order + 1;

            if (nowpos.dir == 1) {
                if (i == 4 || i == 3) {
                    nxtpos.dir = i;
                }
            }
            else if (nowpos.dir == 2) {
                if (i == 3 || i == 4) {
                    nxtpos.dir = i;
                }
            }
            else {
                if (i == 1 || i == 2) {
                    nxtpos.dir = i;
                }
            }
            if (chk[nxtpos.y][nxtpos.x][nxtpos.dir] > nxtpos.order) {
                chk[nxtpos.y][nxtpos.x][nxtpos.dir] = nxtpos.order;
                push(nxtpos);
            }



        }

        for(int i = 1; i < 4; i++) { // GO
            nxtpos.dir = nowpos.dir;
            nxtpos.y = nowpos.y + move[nxtpos.dir][0]*i;
            nxtpos.x = nowpos.x + move[nxtpos.dir][1]*i;
            nxtpos.order = nowpos.order + 1;

            if (check(nxtpos) == 0) {
                break;
            }
            else if (check(nxtpos) == 1){
                continue;
            }
            else {
                chk[nxtpos.y][nxtpos.x][nxtpos.dir] = nxtpos.order;
                push(nxtpos);
            }
        }
    }
    return;
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i  = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            chk[i][j][1] = INF;
            chk[i][j][2] = INF;
            chk[i][j][3] = INF;
            chk[i][j][4] = INF;
        }
    }

    scanf("%d %d %d", &robot.y, &robot.x, &robot.dir);
    robot.order = 1;
    chk[robot.y][robot.x][robot.dir] = 1;
    scanf("%d %d %d", &endpt.y, &endpt.x, &endpt.dir);



    push(robot);
    bfs();
    printf("%d\n", shortest-1);

    return 0;
}