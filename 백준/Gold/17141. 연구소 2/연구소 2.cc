#include <stdio.h>

int N; int M;
int map[55][55] = {0,};
int chk[55][55] = {0,};

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

int st = 0; int ed = 0;
pos queue[10000] = {0,};
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

int shortest = 20000000;

int emptyN = 0;
pos empty[10000] = {0,};

int top = 0;
pos stack[10000] = {0,};

int simul = 0;

int check(pos nxtpos) {
    if (nxtpos.y >= N || nxtpos.y < 0 || nxtpos.x >= N || nxtpos.x < 0) {
        return 0;
    }
    else if (map[nxtpos.y][nxtpos.x] == 1) {
        return 0;
    }
    else if (chk[nxtpos.y][nxtpos.x] != simul) {
        return 1;
    }
    return 0;
}

void pri() {
    printf("%d\n", simul);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (chk[i][j] == simul) {
                printf("5");
            }
            else {
                printf("%d", map[i][j]);
            }
        }
        printf("\n");
    }
    return;
}

void bfs() {
    for (int i = 0; i < M; i++) {
        chk[stack[i].y][stack[i].x] = simul;
        push(stack[i]);
    }
    //pri();
    pos nowpos;
    pos nxtpos;
    while (size() != 0) {
        nowpos = pop();

/*
        if (nowpos.depth >= shortest) {
            printf("%d\n", nowpos.depth);
            return;
        }
*/

        for (int i = 0; i < 4; i++) {
            nxtpos.y = nowpos.y + move[i][0];
            nxtpos.x = nowpos.x + move[i][1];
            nxtpos.depth = nowpos.depth + 1;
            if (check(nxtpos) == 1) {
                chk[nxtpos.y][nxtpos.x] = simul;
                push(nxtpos);
            }
        }
    }
    //pri();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((map[i][j]==0 || map[i][j] == 2) && chk[i][j] != simul) {
                return;
            } 
        }
    }

    //printf("%d\n\n", nowpos.depth);
    if (nowpos.depth < shortest) {
        shortest = nowpos.depth;
    }

    return;
}

void backtraking(int depth, int bef) {
    if (depth == M) {
        simul++;
        
        bfs();
        st = 0;
        ed = 0;
    }

    for (int i = bef; i < emptyN; i++) {
        stack[depth] = empty[i];
        backtraking(depth+1, i+1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    pos tempos;
    tempos.depth = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                tempos.y = i;
                tempos.x = j;
                empty[emptyN++] = tempos;
            }
        }
    }

    backtraking(0, 0);

    if (shortest == 20000000) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", shortest-1);

    return 0;
}