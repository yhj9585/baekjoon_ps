#include <stdio.h>

int R; int C; int T;
int map[55][55] = {0,};
int add[55][55] = {0,};

int move[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
};

void spread(int y, int x) {
    int spreadN = 0;
    int amount = map[y][x]/5;
    int nxty;
    int nxtx;

    for (int i = 0; i < 4; i++) {
        nxty = y + move[i][0];
        nxtx = x + move[i][1];
        if (nxty >= R || nxty < 0 || nxtx >= C || nxtx < 0) {
            continue;
        }
        else if (map[nxty][nxtx] == -1) {
            continue;
        }
        else {
            add[nxty][nxtx] += amount;
            spreadN++;
        }
    }
    map[y][x] = map[y][x] - amount*spreadN;
    return;
}

void air(int airBlower) {
    // UPPER
    for (int i = airBlower-1; i > 0; i--) {
        map[i][0] = map[i-1][0];
    }
    for (int i = 0; i < C-1; i++) {
        map[0][i] = map[0][i+1];
    }
    for (int i = 0; i < airBlower; i++) {
        map[i][C-1] = map[i+1][C-1];
    }
    for (int i = C-1; i > 1; i--) {
        map[airBlower][i] = map[airBlower][i-1];
    }


    // LOWER
    for (int i = airBlower+2; i < R-1; i++) {
        map[i][0] = map[i+1][0];
    }
    for (int i = 0; i < C-1; i++) {
        map[R-1][i] = map[R-1][i+1];
    }
    for (int i = R-1; i > airBlower+1; i--) {
        map[i][C-1] = map[i-1][C-1];
    }
    for (int i = C-1; i > 1; i--) {
        map[airBlower+1][i] = map[airBlower+1][i-1];
    }
    map[airBlower][1] = 0;
    map[airBlower+1][1] = 0;
    return;
}

int main() {
    int airBlower = 0;

    scanf("%d %d %d", &R, &C, &T);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == -1 && airBlower == 0) {
                airBlower = i;
            }
        }
    }

    for (int time = 1; time <= T; time++) {
        // 1st
        for (int i = 0; i < R; i++) {
            for (int j = 0; j <C; j++) {
                if (map[i][j] != 0 && map[i][j] != -1) {
                    spread(i,j);
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] != -1) {
                    map[i][j] = map[i][j] + add[i][j];
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                add[i][j] = 0;
            }
        }

/*
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                printf("%3d", map[i][j]);   
            }
            printf("\n");
        }        
        printf("\n");

*/
        // 2nd
        air(airBlower);

/*
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                printf("%3d", map[i][j]);   
            }
            printf("\n");
        }        
        printf("\n");
*/
    }

    int sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] != -1) {
                sum += map[i][j];
            }
        }
    }
    printf("%d\n", sum);

    return 0;
}