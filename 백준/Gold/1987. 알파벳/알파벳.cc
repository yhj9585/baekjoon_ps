#include <stdio.h>

int R; int C;

int alpha[30];
char map[21][21] = {0,};
int chk[21][21] = {0,};

const int Ais0 = 65;

int move[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
};

typedef struct pos {
    int y;
    int x;
}pos;

pos stack[500] = {0,};

int longest = 0;

void pri() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d", chk[i][j]);
        }
        printf("\n");
    }
}

int check(pos nxtpos) {
    if (nxtpos.y >= R || nxtpos.y < 0 || nxtpos.x >= C || nxtpos.x < 0) {
        return 0;
    }
    else if (alpha[(int)map[nxtpos.y][nxtpos.x]-Ais0] != 0) {
        return 0;
    }
    else if (chk[nxtpos.y][nxtpos.x] != 0) {
        return 0;
    }
    else {
        return 1;
    }
    return 0;
}

void dfs(int depth) {
    
    //printf("NOW : %d\n", depth);
    //pri();
    
    if (depth+1 > longest) {
        longest = depth + 1;
    }
    pos nowpos;
    pos nxtpos;

    nowpos = stack[depth];

    for (int i = 0; i < 4; i++) {
        nxtpos.y = nowpos.y + move[i][0];
        nxtpos.x = nowpos.x + move[i][1];


        if (check(nxtpos) == 1) {
            alpha[(int)map[nxtpos.y][nxtpos.x] - Ais0] = 1;
            chk[nxtpos.y][nxtpos.x] = 1;
            stack[depth+1] = nxtpos;
            dfs(depth+1);
            alpha[(int)map[nxtpos.y][nxtpos.x] - Ais0] = 0;
            chk[nxtpos.y][nxtpos.x] = 0;
        }
        else {
            continue;
        }

    }


    return;
}


int main() {
    scanf("%d %d", &R, &C);
    getchar();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%1c", &map[i][j]);
        }
        getchar();
    }

    pos newpos;
    newpos.y = 0;
    newpos.x = 0;
    chk[0][0] = 1;
    alpha[(int)map[0][0]-Ais0] = 1;
    stack[0] = newpos;

    dfs(0);

    printf("%d\n", longest);
    return 0;
}