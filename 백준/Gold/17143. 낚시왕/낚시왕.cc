#include <stdio.h>

int map[102][102] = {0,};
int R; int C;

typedef struct shark {
    int y;
    int x;
    int dir;
    int size;
    int speed;
    int life;
}shark;
int sharkN;
shark num[10002];

int move[5][2] = {
    { 0, 0},
    {-1, 0},
    { 1, 0},
    { 0, 1},
    { 0,-1}
};  //y,x



int main() {
    int sum = 0;
    scanf("%d %d %d", &R, &C, &sharkN);
    for (int i = 1; i <= sharkN; i++) {
        scanf("%d %d %d %d %d", &num[i].y, &num[i].x, &num[i].speed, &num[i].dir, &num[i].size);
        num[i].life = 1;
        map[num[i].y][num[i].x] = i;
    }

    if (sharkN == 0) {
        printf("0\n");
        return 0;
    }

    for (int time = 1; time <= C; time++) {
        for (int i = 1; i <= R; i++) {
            if (map[i][time] != 0) {
                num[map[i][time]].life = 0;
                sum += num[map[i][time]].size;
                map[i][time] = 0;
                break;
            }
        }

        for(int i = 1; i <= sharkN; i++) {
            map[num[i].y][num[i].x] = 0;
        }

        int tempy; int tempx;
        for (int i = 1; i <= sharkN; i++) {
            if (num[i].life != 0) {
                tempy = num[i].y;
                tempx = num[i].x;   

                int tempN;
                if ((num[i].dir == 1 || num[i].dir == 2)&&num[i].speed > R) {
                    tempN = num[i].speed % (2*(R-1));
                }
                else if ((num[i].dir == 3 || num[i].dir == 4)&&num[i].speed > C) {
                    tempN = num[i].speed % (2*(C-1));
                }
                else {
                    tempN = num[i].speed;
                }

                for (int j = 0; j < tempN; j++) {
                    tempy = tempy + move[num[i].dir][0];
                    tempx = tempx + move[num[i].dir][1];  
                    if (tempy > R || tempy <= 0 || tempx > C || tempx <= 0) {
                        if (num[i].dir == 1) {
                            num[i].dir = 2;
                        }
                        else if (num[i].dir == 2) {
                            num[i].dir = 1;
                        }
                        else if (num[i].dir == 3) {
                            num[i].dir = 4;
                        }
                        else {
                            num[i].dir = 3;
                        }
                        tempy = tempy + move[num[i].dir][0]*2;
                        tempx = tempx + move[num[i].dir][1]*2;  
                    }
                }

                if (map[tempy][tempx] != 0) {
                    if (num[map[tempy][tempx]].size < num[i].size) {
                        num[map[tempy][tempx]].life = 0;
                        num[i].y = tempy;
                        num[i].x = tempx;
                        map[tempy][tempx] = i;
                    }
                    else {
                        num[i].life = 0;
                    }
                }
                else {
                    num[i].y = tempy;
                    num[i].x = tempx;
                    map[tempy][tempx] = i;
                }
            }
        }
        
        /*
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                printf("%d", map[i][j]);
            }
            printf("\n");
        }
        */
    }

    printf("%d\n", sum);
    return 0;
}