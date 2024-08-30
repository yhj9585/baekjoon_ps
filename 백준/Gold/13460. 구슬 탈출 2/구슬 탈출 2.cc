#include <stdio.h>

char map[11][11] = {0,};
int N = 0;
int M = 0;

struct pos {
    int y;
    int x;
};

struct pos move[4] = {
    { -1 ,  0},     //U
    {  1 ,  0},     //D
    {  0 , -1},     //L
    {  0 ,  1}      //R
};

struct node {
    struct pos rPos;
    struct pos bPos;
    int time;
};

struct node queue[10000000] = {0,};

int st = 0;
int ed = 0;

void push(struct node newnode) {
    queue[st++] = newnode;
    return;
}
struct node pop() {
    return queue[ed++];
}
int size() {
    return st - ed;
}

int movement(struct node nownode, int dir) { // first == 1 < red first
    struct node nxtnode;
    struct pos temp1Pos;
    struct pos temp2Pos;
    struct pos nxtPos;

    int end1 = 0;
    int end2 = 0;
    int first;

    if (dir == 0) {
        if (nownode.bPos.y < nownode.rPos.y) {
            first = 2;
        } else {
            first = 1;
        }
    } else if (dir == 1) {
        if (nownode.bPos.y > nownode.rPos.y) {
            first = 2;
        } else {
            first = 1;
        }
    } else if (dir == 2) {
        if (nownode.bPos.x < nownode.rPos.x) {
            first = 2;
        } else {
            first = 1;
        }
    } else {
        if (nownode.bPos.x > nownode.rPos.x) {
            first = 2;
        } else {
            first = 1;
        }
    }

    if (first == 1) {
        temp1Pos = nownode.rPos;
        temp2Pos = nownode.bPos;
    } else {
        temp1Pos = nownode.bPos;
        temp2Pos = nownode.rPos;
    }
    while(1) {
        nxtPos.x = temp1Pos.x + move[dir].x;
        nxtPos.y = temp1Pos.y + move[dir].y;
        if (map[nxtPos.y][nxtPos.x] == '#') {
            break;
        }
        else if (map[nxtPos.y][nxtPos.x] == 'O') {
            end1 = 1;
            temp1Pos.y = 10;
            temp1Pos.x = 10;
            break;
        }
        else if (map[nxtPos.y][nxtPos.x] == '.') {
            temp1Pos = nxtPos;
        }
    }

    while(1) {
        nxtPos.x = temp2Pos.x + move[dir].x;
        nxtPos.y = temp2Pos.y + move[dir].y;
        if (map[nxtPos.y][nxtPos.x] == '#') {
            break;
        }
        else if (nxtPos.y == temp1Pos.y && nxtPos.x == temp1Pos.x) {
            break;
        }
        else if (map[nxtPos.y][nxtPos.x] == 'O') {
            end2 = 1;
            temp2Pos.y = 10;
            temp2Pos.x = 10;
            break;
        }
        else if (map[nxtPos.y][nxtPos.x] == '.') {
            temp2Pos = nxtPos;
        }
    }
    
    if (first == 1) {
        nxtnode.rPos = temp1Pos;
        nxtnode.bPos = temp2Pos;
        nxtnode.time = nownode.time + 1;
    }
    else {
        nxtnode.rPos = temp2Pos;
        nxtnode.bPos = temp1Pos;
        nxtnode.time = nownode.time + 1;
    }

    if (end1 == 1 && end2 == 0 && first == 1) { //sucess
        return nxtnode.time;
    }
    else if (end1 == 0 && end2 == 1 && first == 2) { // sucess
        return nxtnode.time;
    }
    else if (end1 == 1 || end2 == 1) {
        return 0;
    }
    else {
        push(nxtnode);
        return 0;
    }
}

void simulate() {
    struct node nownode; 
    int endchk;

    while(size() != 0) {
        nownode = pop();

        if (nownode.time >= 10) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            endchk = movement(nownode, i);
            if (endchk != 0) {
                printf("%d\n", endchk);
                return;
            }
        }
    }
    printf("-1\n");
}

int main() {
    char tempChar;
    struct node newNode;
    struct pos rPos;
    struct pos bPos;

    scanf("%d %d", &N, &M);
    getchar();
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            scanf("%c", &tempChar);
            if (tempChar == 'R') {
                rPos.x = i;
                rPos.y = j;
                map[j][i] = '.';
            }
            else if (tempChar == 'B') {
                bPos.x = i;
                bPos.y = j;
                map[j][i] = '.';
            }
            else {
                map[j][i] = tempChar;
            }
        }
        getchar();
    }

    newNode.rPos = rPos;
    newNode.bPos = bPos;
    newNode.time = 0;
    push(newNode);

    simulate();

    return 0;
}