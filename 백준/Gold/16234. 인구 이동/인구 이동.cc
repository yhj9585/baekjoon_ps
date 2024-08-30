#include <stdio.h>
#include <stdlib.h>

int N; int L; int R;
int map[51][51] = {0,};
int chk[51][51] = {0,};

struct pos {
    int y;
    int x;
};
struct pos move[4] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
};
struct pos travel[3000];

struct pos queue[100000] = {0,};
int st = 0;
int ed = 0;
void push(struct pos node) {
    queue[st++] = node;
    return;
}
struct pos pop() {
    return queue[ed++];
}
int size() {
    return st-ed;
}

int bfs(int time) {
    struct pos nowpos;
    struct pos nxtpos;
    int dif;
    int div = 1;
    int sum = 0;
    int avg;
    int change = 0;

    while(size() != 0) {
        nowpos = pop();
        sum += map[nowpos.y][nowpos.x];

        for (int i = 0; i < 4; i++) {
            nxtpos.x = nowpos.x + move[i].x;
            nxtpos.y = nowpos.y + move[i].y;
            dif = abs(map[nxtpos.y][nxtpos.x] - map[nowpos.y][nowpos.x]);
            if (nxtpos.x >= 0 && nxtpos.x < N && nxtpos.y >= 0 && nxtpos.y < N) { // 배열 내부인지 확인
                if (chk[nxtpos.y][nxtpos.x] != time) {                              // 방문한 장소인지 확인
                    if (dif <= R && dif >= L) {
                        chk[nxtpos.y][nxtpos.x] = time;
                        push(nxtpos);
                        travel[div++] = nxtpos;
                    }
                }
            }
        }
    }

    if (div == 1) {
        return 0;
    }

    avg = sum/div;
    for (int i = 0; i < div; i++) {
        if (map[travel[i].y][travel[i].x] != avg) {
            change = 1;
        }
        map[travel[i].y][travel[i].x] = avg;
    }


    if (change == 0) {
        return 0;
    } else {
        return 1;
    }

}

void simul() {
    int time = 0;
    int change = 1;
    struct pos temp;
    int moving = 0;

    while (change == 1) {
        moving = 0;
        time++;
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                if (chk[j][i] != time) {
                    chk[j][i] = time;
                    temp.y = j;
                    temp.x = i;
                    st = 0;
                    ed = 0;
                    push(temp);
                    travel[0] = temp;
                    if (bfs(time) == 1 && moving == 0) {
                        moving = 1;
                    }
                }
            }
        }
        if (moving == 0) {
            change = 0;
        }
    }

    printf("%d\n", time-1);

    return;

}

int main() {
    scanf("%d %d %d", &N, &L, &R);
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &map[j][i]);
        }
    }

    simul();
    return 0;
}