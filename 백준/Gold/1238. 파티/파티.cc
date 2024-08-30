//#pragma warning (disable:4996)
#include <stdio.h>

int N; int M; int X;
// N = Num of Vil
// M = Num of Road
// X = Place to Party

static int INF = 987654321;
int TimetoGo[1001][1001];

int chk[2][1001];
int dis[2][1001];


int getSmall(int dir) {
    int small = INF;
    int smallpos = 0;
    for (int i = 1; i <= N; i++) {
        if (dis[dir][i] < small && chk[dir][i] == 0) {
            small = dis[dir][i];
            smallpos = i;
        }
    }
    return smallpos;
}

int main() {
    scanf("%d %d %d", &N, &M, &X);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            TimetoGo[i][j] = INF;
        }
    }

    int fromV; int toV; int timeTo;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &fromV, &toV, &timeTo);
        TimetoGo[fromV][toV] = timeTo;
    }


    // from X to home
    for (int i = 1; i <= N; i++) {
        dis[0][i] = TimetoGo[X][i];
    }

    chk[0][X] = 1;
    for (int i = 1; i < N - 1; i++) {
        int now = getSmall(0);
        chk[0][now] = 1;
        for (int j = 1; j <= N; j++) {
            if (chk[0][j] == 0) {
                if (dis[0][now] + TimetoGo[now][j] < dis[0][j]) {
                    dis[0][j] = dis[0][now] + TimetoGo[now][j];
                }
            }
        }
    }

    // from home to X
    for (int i = 1; i <= N; i++) {
        dis[1][i] = TimetoGo[i][X];
    }

    chk[1][X] = 1;
    for (int i = 1; i < N - 1; i++) {
        int now = getSmall(1);
        chk[1][now] = 1;
        for (int j = 1; j <= N; j++) {
            if (chk[1][j] == 0) {
                if (dis[1][now] + TimetoGo[j][now] < dis[1][j]) {
                    dis[1][j] = dis[1][now] + TimetoGo[j][now];
                }
            }
        }
    }

    int large = 0;
    for (int i = 1; i <= N; i++) {
        if (i != X) {
            if (dis[0][i] + dis[1][i] > large) {
                large = dis[0][i] + dis[1][i];
            }
        }
    }

    printf("%d\n", large);

    return 0;
}