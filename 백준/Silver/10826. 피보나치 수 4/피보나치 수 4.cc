#include <stdio.h>

int Fn2[2100] = {0,};
int Fn1[2100] = {0,};
int Fn[2100] = {0,};

int HowLong = 0;

int N;

int main() {
    scanf("%d", &N);
    int over;

    Fn[0] = 0;
    Fn1[0] = 1;

    for (int i = 2; i <= N; i++) {
        Fn2[0] = (Fn1[0]+Fn[0])%10;
        if (Fn1[0]+Fn[0] > 9) {
            if (HowLong == 0) {
                HowLong++;
            }
            over = 1;
        }
        else {
            over = 0;
        }

        for (int j = 1; j <= HowLong; j++) {
            Fn2[j] = (Fn1[j]+Fn[j]+over)%10;
            if (Fn1[j]+Fn[j]+over>9) {
                over = 1;
                if (j == HowLong) {
                    HowLong++;
                }
            }
            else {
                over = 0;
            }
        }

        for (int j = 0; j <= HowLong; j++) {
            Fn[j] = Fn1[j];
            Fn1[j] = Fn2[j];
        }
/*
        printf("%dth Fibo : ",i);
        if (N == 1) {
            printf("1\n");
        }
        else if (N == 0) {
            printf("0\n");
        }
        else {
            for (int j = HowLong; j >= 0; j--) {
                printf("%d", Fn1[j]);
            }
            printf("\n");
        }
*/
    }
    
    if (N == 1) {
        printf("1\n");
    }
    else if (N == 0) {
        printf("0\n");
    }
    else {
        for (int i = HowLong; i >= 0; i--) {
            printf("%d", Fn1[i]);
        }
        printf("\n");
    }
    return 0;
}