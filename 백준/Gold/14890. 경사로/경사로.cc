#include <stdio.h>

int N; int L;
int map[101][101] = {0,};
int chk[2][101][101] = {0,};




int main() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // ROW
    int road = 0;
    int able = 1;
    for (int i = 0; i < N; i++) {
        able = 1;
        for (int j = 0; j < N-1; j++) {
            //chk[i][j][0] = 1;
            if (map[i][j] - map[i][j+1] == 1) {
                if (j+L >= N) {
                    able = 0;
                    break;
                }
                for (int brig = 1; brig <= L; brig++) {
                    if (chk[0][i][j+brig] != 0) {
                        able = 0;
                        break;
                    }
                    if (map[i][j] - map[i][j+brig] == 1) {
                        chk[0][i][j+brig] = 1;
                    }
                    else {
                        able = 0;
                        break;
                    }
                }
                if (able == 1) {
                    j = j+L-1;
                }
            }
            else if (map[i][j] - map[i][j+1] > 1) {
                able = 0;
            }

            if (able == 0) {
                break;
            }
        }

        for (int j = N-1; j > 0; j--) {
            if (map[i][j] - map[i][j-1] == 1) {
                if (j-L < 0) {
                    able = 0;
                    break;
                }
                for (int brig = 1; brig <= L; brig++) {
                    if (chk[0][i][j-brig] != 0) {
                        able = 0;
                        break;
                    }
                    if (map[i][j] - map[i][j-brig] == 1) {
                        chk[0][i][j-brig] = 1;
                    }
                    else {
                        able = 0;
                        break;
                    }
                }
                if (able == 1) {
                    j = j-L+1;
                }
            }

            else if (map[i][j] - map[i][j-1] > 1) {
                able = 0;
            }
            if (able == 0) {
                break;
            }

        }
/*
        for (int y = 0; y < N; y++) {
            printf("%d", map[i][y]);
        }
        printf("\n");
        for (int y = 0; y < N; y++) {
            printf("%d", chk[0][i][y]);
        }
        printf("\n");
*/
        if (able == 1) {
            road++;
            //printf("%d\n", able);
        }
    }

    //printf("\n");   

    // COL
    able = 1;
    for (int i = 0; i < N; i++) {
        able = 1;
        for (int j = 0; j < N-1; j++) {
            if (map[j][i] - map[j+1][i] == 1) {
                if (j+L >= N) {
                    able = 0;
                    break;
                }
                for (int brig = 1; brig <= L; brig++) {
                    if (map[j][i] - map[j+brig][i] == 1) {
                        chk[1][j+brig][i] = 1;
                    }
                    else {
                        able = 0;
                        break;
                    }
                }
                if (able == 1) {
                    j = j+L-1;
                }
            }
            else if (map[j][i] - map[j+1][i] > 1) {
                able = 0;
            }

            if (able == 0) {
                break;
            }
        }

        for (int j = N-1; j > 0; j--) {
            if (map[j][i] - map[j-1][i] == 1) {
                if (j-L < 0) {
                    able = 0;
                    break;
                }
                for (int brig = 1; brig <= L; brig++) {
                    if (chk[1][j-brig][i] != 0) {
                        able = 0;
                        break;
                    }
                    if (map[j][i] - map[j-brig][i] == 1) {
                        chk[1][j-brig][i] = 1;
                    }
                    else {
                        able = 0;
                        break;
                    }
                }
                if (able == 1) {
                    j = j-L+1;
                }
            }
            else if (map[j][i] - map[j-1][i] > 1) {
                able = 0;
            }
            if (able == 0) {
                break;
            }

        }

/*
        for (int y = 0; y < N; y++) {
            printf("%d", map[y][i]);
        }
        printf("\n");
        for (int y = 0; y < N; y++) {
            printf("%d", chk[1][y][i]);
        }
        printf("\n");
*/
        if (able == 1) {
            //printf("%d\n", able);
            road++;
        }
    }


    printf("%d\n", road);

    return 0;
}