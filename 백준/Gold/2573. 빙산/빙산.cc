#include <stdio.h>

int N; int M;
int map[301][301] = {0,};
int chk[301][301] = {0,};
int melting[301][301] = {0,};

int glacierN = 0;
int Nowglacier;

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

pos glacier[90000] = {0,};

int st = 0; int ed = 0;
pos queue[90001] = {0,};
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

int nowtime = 0;

int check(pos nxtpos) {
    if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= M || nxtpos.x < 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 0) {
        return 2;
    }
    else if (chk[nxtpos.y][nxtpos.x] != nowtime) {
        return 1;
    }
    return 0;
}

void pri() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
                printf("%d", map[i][j]);
        }
        printf("\n");
    }
    printf("CHK\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
                printf("%d", chk[i][j]);
        }
        printf("\n");
    }
    return;
}



int bfs() {
    //pri();
    pos nowpos;
    pos nxtpos;
    int connectN = 0;
    int meltN;
    while (size() != 0) {
        nowpos = pop();
        connectN++;

        meltN = 0;

        for (int i = 0; i < 4; i++) {
            nxtpos.y = nowpos.y + move[i][0];
            nxtpos.x = nowpos.x + move[i][1];
            if (check(nxtpos) == 1) {
                chk[nxtpos.y][nxtpos.x] = nowtime;
                push(nxtpos);
            } 
            else if (check(nxtpos) == 2) {
                meltN++;
            }
        }
        melting[nowpos.y][nowpos.x] = meltN;
    }

    //pri();
    if (connectN != Nowglacier) {
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

void simul() {
    Nowglacier = glacierN;
    while(1) {
        nowtime++;
        st = 0; ed = 0;
        for (int i = 0; i < glacierN; i++) {
            if (map[glacier[i].y][glacier[i].x] != 0) {
                push(glacier[i]);
                chk[glacier[i].y][glacier[i].x] = nowtime;
                break;
            }
        }
        if (st == 0) {
            printf("0\n");
            return;
        }
        
        if (bfs() == 1) {
            printf("%d\n", nowtime-1);
            //pri();
            return;
        }

        //printf("NOW : %d\n", nowtime);
        
        for (int i = 0; i < glacierN; i++) { 
            if (map[glacier[i].y][glacier[i].x] != 0) {
                if (melting[glacier[i].y][glacier[i].x] >= map[glacier[i].y][glacier[i].x]) {
                    map[glacier[i].y][glacier[i].x] = 0;
                    Nowglacier--;
                }
                else {
                    map[glacier[i].y][glacier[i].x] -= melting[glacier[i].y][glacier[i].x]; 
                }
                melting[glacier[i].y][glacier[i].x] = 0;
            }
        }
        //pri();
    }
    printf("0\n");
    return;
}

int main() {
    scanf("%d %d", &N, &M);
    pos tempos;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] != 0) {
                tempos.y = i;
                tempos.x = j;
                glacier[glacierN++] = tempos;
            }
        }
    }

    simul();

    return 0;
}