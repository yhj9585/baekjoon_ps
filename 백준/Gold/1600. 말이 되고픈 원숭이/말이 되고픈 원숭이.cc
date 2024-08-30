#include <stdio.h>

int W; int H; int K;
int map[202][202] = {0,};
int chk[33][202][202] = {0,};

int move[12][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1},
    {-2,-1},
    {-2, 1},
    {-1,-2},
    {-1, 2},
    { 1,-2},
    { 1, 2},
    { 2,-1},
    { 2, 1}
};

typedef struct pos {
    int y;
    int x;
    int jump;
    int depth;
}pos;

int st = 0; int ed = 0;
pos queue[5000000] = {0,};
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
    if (nxtpos.y >= H || nxtpos.y < 0 || nxtpos.x >= W || nxtpos.x < 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] != 0) {
        return 0;
    }
    else if (chk[nxtpos.jump][nxtpos.y][nxtpos.x] != 0) {
        return 0;
    }
    return 1;
}

void bfs() {
    pos newpos;
    newpos.y = 0;
    newpos.x = 0;
    newpos.jump = K;
    newpos.depth = 0;
    chk[K][0][0] = 1;
    push(newpos);


    pos nowpos;
    pos nxtpos;
    while (size() != 0) {
        nowpos = pop();
        if (nowpos.y == H-1 && nowpos.x == W-1) {
            printf("%d\n", nowpos.depth);
            return;
        }


        for (int i = 0; i < 12; i++) {
            nxtpos.y = nowpos.y + move[i][0];
            nxtpos.x = nowpos.x + move[i][1];
            nxtpos.jump = nowpos.jump;
            nxtpos.depth = nowpos.depth + 1;
            if (i >= 4) {
                if (nowpos.jump <= 0) {
                    break;
                }
                else {
                    nxtpos.jump--;
                }
            }


            if (check(nxtpos) == 1) {
                push(nxtpos);
                chk[nxtpos.jump][nxtpos.y][nxtpos.x] = 1;
            }
        }        


    }

    printf("-1\n");


    return;
}



int main() {
    scanf("%d", &K);
    scanf("%d %d", &W, &H);
    for(int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    bfs();

    return 0;
}