#include <stdio.h>

int N; int M;
int map[101][101] = {0,};
int chk[101][101] = {0,};

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

int st = 0; int ed = 0;
pos queue[10001] = {0,};
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

int timeTomelt = 0;

int check(pos nxtpos) {
    if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= M || nxtpos.x < 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 1) {
        return 2;
    }
    else if (map[nxtpos.y][nxtpos.x] == 0 && chk[nxtpos.y][nxtpos.x] == 0) {
        return 1;
    }
    return 0;

}

void pri() {
    printf("MAP\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    printf("CHK\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", chk[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return;
}

void bfs() {
    int melt = 0;
    pos newpos;
    pos nowpos;
    pos nxtpos;


    while (melt == 0) {
        melt = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1) {
                    melt = 0;
                    break;
                }
            }
            if (melt == 0) {
                break;
            }
        }

        if (melt == 1) {
            printf("%d\n", timeTomelt);
            return;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                chk[i][j] = 0;
            }
        }        

        st = 0;
        ed = 0;
        newpos.y = 0;
        newpos.x = 0;
        chk[0][0] = 1;
        push(newpos);
        timeTomelt++;
        
        while(size() != 0) {
            nowpos = pop();
            
            for (int i = 0; i < 4; i++) {
                nxtpos.y = nowpos.y + move[i][0];
                nxtpos.x = nowpos.x + move[i][1];
                if (check(nxtpos) == 1) {
                    chk[nxtpos.y][nxtpos.x] = 1;
                    push(nxtpos);
                }
                else if (check(nxtpos) == 2) {
                    chk[nxtpos.y][nxtpos.x]++;

                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (chk[i][j] >= 2) {
                    map[i][j] = 0;
                }
            }
        }
        //pri();

    }

    return;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    bfs();

    return 0;
}

