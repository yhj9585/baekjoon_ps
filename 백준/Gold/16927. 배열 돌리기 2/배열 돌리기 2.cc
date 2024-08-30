#include <stdio.h>

int N; int M;
int R;

int smaller;

int map[303][303] = {0,};

void pri() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void rot() {
    int alterR;
    int startp;

    if (N < M) {
        smaller = N;
    }
    else {
        smaller = M;
    }

    for (int i = 1; i <= smaller/2; i++) {
        if (R > 2*N+2*M-8*i+4) {
            alterR = R%(2*N+2*M-8*i+4);
        }
        else if (R == 2*N+2*M-8*i+4) {
            alterR = 0;
        }
        else {
            alterR = R;
        }

        for (int time = 0; time < alterR; time++) {
            startp = map[i][i];
            for (int j = i; j <= M-i; j++) {
                map[i][j] = map[i][j+1];
            }
            for (int j = i; j <= N-i; j++) {
                map[j][M+1-i] = map[j+1][M+1-i];
            }
            for (int j = M+1-i; j > i; j--) {
                map[N+1-i][j] = map[N+1-i][j-1];
            }
            for (int j = N+1-i; j > i+1; j--) {
                map[j][i] = map[j-1][i];
            }
            map[i+1][i] = startp;
        }
    }


    return ;
}

int main() {
    scanf("%d %d %d", &N, &M, &R);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    rot();
    pri();

    return 0;
}