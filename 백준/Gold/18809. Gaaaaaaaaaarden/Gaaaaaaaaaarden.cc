#include <stdio.h>

int N; int M; int G; int R;
int map[51][51] = {0,};
int chk[51][51] = {0,};
int var[51][51] = {0,};


int flowerL = 0;

//var1 = Green
//var2 = Red
typedef struct pos {
    int y;
    int x;
    int var;
}pos;

int gN = 0;
pos ground[11] = {0,};

pos move[4] = {
    {-1, 0, 0},
    { 1, 0, 0},
    { 0,-1, 0},
    { 0, 1, 0}
};

pos queue[10000] = {0,};
int st; int ed;
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

int check(pos nxtPos, int color, int time) {
    if (nxtPos.y >= N || nxtPos.y < 0 || nxtPos.x >= M || nxtPos.x < 0) {
        return 0; // OUT OF BOUND
    }

    if (map[nxtPos.y][nxtPos.x] == 0) {
        return 0; // ON POUND
    }
    if (chk[nxtPos.y][nxtPos.x] != 0) {
        if ((color == 1 && var[nxtPos.y][nxtPos.x] == 2) || (color == 2 && var[nxtPos.y][nxtPos.x] == 1)) {
            if (chk[nxtPos.y][nxtPos.x] == time) {
                return 3; // FLOWER   
            }
            else {
                return 0; // NO 
            }
        }
        else {
            return 0; // CANT 
        }
    }
    else {
        return 1;
    }
}

pos seed[11] = {0,};
int seedN = 0;
void bfs() {
    for (int i = 0; i < seedN; i++) {
        var[seed[i].y][seed[i].x] = seed[i].var;
        chk[seed[i].y][seed[i].x] = 1;
        push(seed[i]);    
    }

    /*
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (var[i][j] != 0) {
                printf("%d", var[i][j]*4);
            }
            else {
                printf("%d", map[i][j]);
            }
        }
        printf("\n");
    }
    */


    int nFlower = 0;
    pos nPos;
    pos nxtPos;
    while (size() != 0) {
        nPos = pop();
        if (var[nPos.y][nPos.x] == 3) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            nxtPos.y = nPos.y + move[i].y;
            nxtPos.x = nPos.x + move[i].x;
            switch (check(nxtPos, var[nPos.y][nPos.x], chk[nPos.y][nPos.x]+1)) {
                case 1:
                    var[nxtPos.y][nxtPos.x] = var[nPos.y][nPos.x];
                    chk[nxtPos.y][nxtPos.x] = chk[nPos.y][nPos.x] + 1;
                    push(nxtPos);
                    break;
                case 3:
                    var[nxtPos.y][nxtPos.x] = 3;
                    nFlower++;
                    break;
                default:
                    break;
            }
                    
        }
    }

    if (nFlower > flowerL) {
        flowerL = nFlower;
    }
    /*
    printf("%d\n",nFlower);
    printf("\n");
    */
    // RESET AFTER SIMULATE
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            var[i][j] = 0;
            chk[i][j] = 0;
        }
    }
    st = 0;
    ed = 0;

    return;
}

//int greenN = 0;
//int redN = 0;
void btrakg(int depth, int preG, int preR) {
    if (depth == R + G) {
        bfs();
        return;
    }

    if (seedN < G) {
        for (int i = preG; i < gN; i++) {
            if (ground[i].var == 0) {
                seed[seedN] = ground[i];
                seed[seedN].var = 1;
                ground[i].var = 1;
                seedN++;
                btrakg(depth+1, i, 0);
                ground[i].var = 0;
                seedN--;
            }
        }
    }   
    else {
        for (int i = preR; i < gN; i++) {
            if (ground[i].var == 0) {
                seed[seedN] = ground[i];
                seed[seedN].var = 2;
                ground[i].var = 2;
                seedN++;
                btrakg(depth+1, 0, i);
                ground[i].var = 0;
                seedN--;
            }
        }
    }
    return;
}


int main() {
    scanf("%d %d %d %d", &N, &M, &G, &R);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                ground[gN].x = j;
                ground[gN++].y = i;
            }
        }
    }
    btrakg(0,0,0);
    printf("%d\n", flowerL);
    return 0;
}