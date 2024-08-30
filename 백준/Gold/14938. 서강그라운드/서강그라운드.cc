#include <stdio.h>

const int INF = 987654321;
int road[102][102];
int item[102];
int able[102] = {0,};

int N; int M; int R;


int main() {
    int pre;
    int nxt;
    int lng;

    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++){
            road[i][j] = INF;
        }
    }

    scanf("%d %d %d", &N, &M, &R);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &item[i]);
        road[i][i] = 0;
    }
    for (int i = 1; i <= R; i++) {
        scanf("%d %d %d", &pre, &nxt, &lng);
        road[pre][nxt] = lng;
        road[nxt][pre] = lng;
    }


    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {  
                if (road[k][j] == INF || road[i][k] == INF) {
                    continue;
                }
                if (road[i][j] > road[i][k] + road[k][j]) {
                    road[i][j] = road[i][k] + road[k][j];
                }
            }
        }
    }


    int most = 0;
    for (int i = 1; i <= N; i++) {
        //able[i] = item[i];
        for (int j = 1; j <= N; j++) {    
            if (road[i][j] <= M) {
                able[i] += item[j];
            }
        }
        if (able[i] > most) {
            most = able[i];
        }
    }

    printf("%d\n", most);

    return 0;
}