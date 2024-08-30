#include <stdio.h>

int map[22][22] = {0,};
int N; int M;
int xpos; int ypos;

int move[5][2] = {
    { 0, 0},
    { 0, 1},
    { 0,-1},
    {-1, 0},
    { 1, 0}
};

int dice[7] = {0, 0, 0, 0, 0, 0, 0};

void dice_move(int dir) {
    int temp;
    if (dir == 1) {
        temp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    }
    else if (dir == 2) {
        temp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
    }
    else if (dir == 3) {
        temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }
    else {
        temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }
    return;
}

/*
    {0, 2, 0},
    {4, 1, 3},
    {0, 5, 0},
    {0, 6, 0}
*/

// east = 1
// west = 2
// north = 3
// south = 4

int orderN[1001] = {0,};

int main() {


    int order;
    scanf("%d %d %d %d %d", &N, &M, &ypos, &xpos, &order);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < order; i++) {
        scanf("%d", &orderN[i]);
    }



    for(int i = 0; i < order; i++) {
        if (xpos+move[orderN[i]][1] >= M || xpos+move[orderN[i]][1] < 0 || ypos+move[orderN[i]][0] >= N || ypos+move[orderN[i]][0] < 0) {
            continue;
        }
        else {
            xpos = xpos + move[orderN[i]][1];
            ypos = ypos + move[orderN[i]][0];
            dice_move(orderN[i]);

            if (map[ypos][xpos] == 0) {
                map[ypos][xpos] = dice[6];
            }
            else {
                dice[6] = map[ypos][xpos];
                map[ypos][xpos] = 0;
            }


            printf("%d\n", dice[1]);
        }

    }



     
    return 0;
}