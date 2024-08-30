#include <stdio.h>

int map[1001][1001] = {0,};
int chk[1001][1001] = {0,};
int H;
int W;

struct pos {
    int y;
    int x;
    int time;
};

struct pos queue[1000001];
int st = 0;
int ed = 0; 

int move[8][2] = {
    {-1, -1},
    {-1,  0},
    {-1,  1},
    { 0, -1},
    { 0,  1},
    { 1, -1},
    { 1,  0},
    { 1,  1}
};

void push(struct pos nonNum) {
    queue[ed] = nonNum;
    ed++;
}
struct pos pop() {
    struct pos ps;
    ps.y = queue[st].y;
    ps.x = queue[st].x;
    ps.time = queue[st].time;
    st++;
    return ps;
}
int size() {
    return ed-st;
}

int test() {
    int max = 0;
    struct pos nowPos;
    struct pos nxtPos;
    while(1) {
        nowPos = pop();
        for (int i = 0; i < 8; i++) {
            nxtPos.y = nowPos.y + move[i][0];
            nxtPos.x = nowPos.x + move[i][1];
            nxtPos.time = nowPos.time + 1;
            if (nxtPos.y < 1 || nxtPos.x < 1 || nxtPos.y > H || nxtPos.x > W) {
                continue;
            }
            if (map[nxtPos.y][nxtPos.x] != 0) {
                map[nxtPos.y][nxtPos.x]--;
                chk[nxtPos.y][nxtPos.x]++;


                if (map[nxtPos.y][nxtPos.x] == 0) {
                    push(nxtPos);
                    if (nxtPos.time > max) {
                       max = nxtPos.time;
                    }
                }
            }
        }
        if (size() == 0) {
            break;
        }
    }
    return max;
}

int main() {
    char temp;
    struct pos nonNum;

    // inPut
    scanf("%d %d", &H, &W);
    getchar(); 
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            scanf("%1c", &temp);
            if (temp == '.') {
                map[i][j] = 0;
                nonNum.y = i;
                nonNum.x = j;
                nonNum.time = 0;
                push(nonNum);
            }
            else {
                map[i][j] = temp - 48;
            }
        }
        getchar();
    }

    printf("%d", test());

}