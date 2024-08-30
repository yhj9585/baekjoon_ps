#include <stdio.h>


int map[10][10] = {0,};
int tmap[10][10] = {0,};
int N;
int M;
int safezone = 0;
int time = 1;

int move[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
};

struct node {
    int y;
    int x;
};

struct node virus[70] = {0,};
int virusN = 0;


int st;
int ed;
struct node queue[100000]  = {0,};
void push(int y, int x) {
    queue[st].y = y;
    queue[st++].x = x;
    return;
}
struct node pop() {
    return queue[ed++];
}
int size() {
    return st-ed;
}

void spread() {
    struct node nownode;
    time++;
    int nxty;
    int nxtx;
    st = 0;
    ed = 0;

    for (int i = 0; i < virusN; i++) {
        push(virus[i].y, virus[i].x);
    }

    while (size() != 0) {
        nownode = pop();
        for (int i = 0; i < 4; i++) {
            nxty = nownode.y + move[i][0];
            nxtx = nownode.x + move[i][1];
            if (nxtx >= 0 && nxty >= 0 && nxtx < M && nxty < N) {
                if (tmap[nxty][nxtx] != time && map[nxty][nxtx] == 0) {
                    tmap[nxty][nxtx] = time;
                    push(nxty, nxtx);
                }
            }
        }
    }

    int safe = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            if(map[j][i] == 0 && tmap[j][i] != time) {
                safe++;
            }
        }
    }
    if (safe > safezone) {
        safezone = safe;
    }

/*
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {  
            if (tmap[j][i] == time) {
                printf("2");
            }
            else {
                printf("%d", map[j][i]);
            }
        }
        printf("\n");
    }
    printf("%d\n", safe);
*/
    return;

}


void simul(int depth) {

    if (depth == 3) {
        spread();
        return;
    }
    depth++;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++){

            if (map[j][i] == 0) {
                map[j][i] = 1;
                simul(depth);
                map[j][i] = 0;
            }
        }
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);
    struct node tempV;

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            scanf("%d", &map[j][i]);
            tmap[j][i] = map[j][i];
            if (map[j][i] == 2) {
                tempV.y = j;
                tempV.x = i;
                virus[virusN].y = tempV.y;
                virus[virusN++].x = tempV.x;
            }
        }
    }

    simul(0);
    printf("%d\n", safezone);
    return 0;
}