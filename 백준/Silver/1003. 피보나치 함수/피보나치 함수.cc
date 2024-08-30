#include <stdio.h>
#include <string.h>

unsigned long long fiboN[50] = {0,};

int main() {
    int tc = 0;
    int largelast = 2;
    int temp = 0;

    fiboN[0] = 0;
    fiboN[1] = 1;

    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        scanf("%d", &temp);
        if (temp >= largelast) {
            for (int j = largelast; j <= temp; j++) {
                fiboN[j] = fiboN[j-1] + fiboN[j-2];
            }
            largelast = temp;
        }
        if (temp != 0) {
            printf("%llu %llu\n", fiboN[temp-1], fiboN[temp]);
        }
        else if (temp == 0) {
            printf("1 0\n");
        }
    }



    return 0;
}