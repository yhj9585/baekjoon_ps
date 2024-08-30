#include <stdio.h>

const int INF = 987654321;
int TestCase;
int K;

int File[555][555] = {0,};
int price[555][555] = {0,};

void pri()  {
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= K; j++) {
            printf("%2d ", File[i][j]);
        }
        printf("\n");
    }
    return;
}

int main() {
    int small = INF;
    int nxtadd;

    scanf("%d", &TestCase);

    for (int tc = 0; tc < TestCase; tc++){
        scanf("%d", &K);
        for (int i = 1; i <= K; i++) {
            scanf("%d", &File[1][i]);
        }



        for (int line = 2; line <= K; line++) {
            for (int page = 1; page <= K-line+1; page++) {
                small = INF;
                for (int temp = 1; temp <= line-1; temp++) {
                    nxtadd = File[temp][page]+File[line-temp][page+temp];
                    if (price[temp][page] + price[line-temp][page+temp] < small) {
                        small = price[temp][page] + price[line-temp][page+temp];
                    }
                }
                File[line][page] = nxtadd;
                price[line][page] = small + nxtadd;
            }
        }
        //pri();
        printf("%d\n", price[K][1]);
    }
    return 0;
}