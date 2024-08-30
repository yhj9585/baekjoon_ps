#include <stdio.h>

int N; int M;
int map[101][101] = {0,};
int chk[101][101] = {0,};

int move[8][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1},
    {-1,-1},
    {-1, 1},
    { 1,-1},
    { 1, 1}
};

typedef struct pos{
    int y;
    int x;
}pos;

int st = 0; int ed = 0;
pos queue[10001] = {0,};
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

int mountN = 0;

void pri() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", chk[i][j]);
        }
        printf("\n");
    }
    printf("MountN : %d\n", mountN);

}

int check(pos nxtpos, int stdH, int nowH) {
    if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= M || nxtpos.x < 0) {
        return 0;
    }
    else if (chk[nxtpos.y][nxtpos.x] != 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] > stdH && nowH == stdH) {
        return 3;
    }
    else if (map[nxtpos.y][nxtpos.x] <= nowH) {
        return 1;
    } 
    else {
        return 0;
    }
}

void dfs() {
    int mountable = 1;
    int stdH;
    int nowH;
    pos nowpos;
    pos nxtpos;

    stdH = map[queue[ed].y][queue[ed].x]; // FIRST HEIGHT

    while(size() != 0) {
        nowpos = pop();
        nowH = map[nowpos.y][nowpos.x];

        for (int i = 0; i < 8; i++) {
            nxtpos.y = nowpos.y + move[i][0];
            nxtpos.x = nowpos.x + move[i][1];
            
            switch (check(nxtpos, stdH, nowH)) {
                case 0:
                    break;
                case 1:
                    chk[nxtpos.y][nxtpos.x] = 1;
                    push(nxtpos);
                    break;
                case 3:
                    mountable = 0;
                    break;
            };
        }
    }
    
    if (mountable == 1) {
        mountN++;
    }
    //pri();
    return;
}

int main() {
    int High = 0;
    pos height;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] > High) {
                High = map[i][j];
                height.y = i;
                height.x = j;
            }
        }
    }

    chk[height.y][height.x] = 1;
    push(height);
    dfs();

    pos newpos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (chk[i][j] == 0) {
                st = 0; ed = 0;
                newpos.y = i;
                newpos.x = j;
                chk[i][j] = 1;
                push(newpos);
                dfs();
            }
        }
    }
    
    printf("%d\n", mountN);

    return 0;
}