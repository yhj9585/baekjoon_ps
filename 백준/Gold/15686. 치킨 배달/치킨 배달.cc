#include <stdio.h>
#include <stdlib.h>

int N; int M;
int map[50][50] = {0,};
int chickdis[101][14] = {0,};
int houseN = 0;
int chickN = 0;
int shortest = 5000;

int queue[20] = {0,};
int st;

void push(int n) {
    queue[st++] = n;
    return;
}
int pop() {
    return queue[--st];
}

void chk() {
    int small = 1000; int sum = 0;
    for(int i = 0; i < houseN; i++) {
        for (int j = 0; j < M; j++) {
            if (chickdis[i][queue[j]] < small) {
                small = chickdis[i][queue[j]];
            }
        }
        sum += small;
        if (sum > shortest) {
            return;
        }
        small = 1000;
    }

    if (sum < shortest) {
        shortest = sum;
    }
    return;
}

void backtracking(int bef, int depth) {
    if (depth == M) {
        chk();
        return;
    }
    for (int i = bef+1; i < chickN; i++) {
        push(i);
        backtracking(i, depth+1);
        pop();
    }
    return;
}



int main() {

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int chickTemp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) {
                
                for (int y = 0; y < N; y++) {
                    for (int x = 0; x < N; x++) {
                        if (map[y][x] == 2) {
                            chickdis[houseN][chickTemp++] = abs(y-i) + abs(x-j);
                        }
                    }
                }
                chickN = chickTemp;
                chickTemp = 0;
                houseN++;
            }
        }
    }

    backtracking(-1,0);

    printf("%d\n", shortest);

    return 0;
}