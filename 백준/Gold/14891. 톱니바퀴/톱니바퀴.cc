#include <stdio.h>
#include <math.h>

int poli[5][8] = {0,};
int rotable[7] = {0,};
// [0] == NORTH == POINT
// [2] == EAST  == ROTATE[2]
// [6] == WEST  == ROTATE[1]


void rotation(int num, int arrow) {
    int temp;
    if (arrow == -1) {
        temp = poli[num][0];
        for (int i = 0; i < 7; i++) {
            poli[num][i] = poli[num][i+1];
        }
        poli[num][7] = temp;
    }
    else {
        temp = poli[num][7];
        for (int i = 7; i > 0; i--) {
            poli[num][i] = poli[num][i-1];
        }
        poli[num][0] = temp;
    }
    return;
}

int main() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &poli[i][j]);
        }
    }
    
    int testcase;
    int rot;
    int num;
    int check;
    scanf("%d", &testcase);
    for (int tc = 1; tc <= testcase; tc++) {
        scanf("%d %d", &num, &rot);

        for (int i = 1; i < 4; i++) {
            if (poli[i][2] != poli[i+1][6]) {
                rotable[i] = 1;
            }
        }

        rotation(num, rot);
        check = num%2;

        // TOWARD WEST 
        for (int i = num-1; i > 0; i--) {
            if (rotable[i] == 1) {
                if (i%2 == check) {
                    rotation(i,rot);
                }
                else {
                    if (rot == 1) {
                        rotation(i,-1);
                    }
                    else {
                        rotation(i,1);
                    }
                }           
            } else {
                i = 5;
                break;
            }
        }


        // TOWARD EAST
        for (int j = num; j < 4; j++) {
            if (rotable[j] == 1) {
                if (((j+1)%2) == check) {
                    rotation(j+1,rot);
                }
                else {
                    if (rot == 1) {
                        rotation(j+1, -1);
                    }
                    else {
                        rotation(j+1,1);
                    }
                }
            } 
            else {
                j = 5;
                break;
            }
        }

        for (int i = 0; i < 5; i++) {
            rotable[i] = 0;
        }

/*
        //print
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%d", poli[i][j]);
            }
            printf("\n");
        }
        printf("\n");
*/
    }


    int sum = 0;
    for (int i = 1; i <= 4; i++) {
        sum += poli[i][0]*(int)pow(2,i-1);
    }

    printf("%d\n", sum);

    return 0;
}