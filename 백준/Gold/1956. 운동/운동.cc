#include <stdio.h>
#include <string.h>

int V; int E;
const int INF = 210000000;
int Road[500][500];

int shortest = INF;

int main() {
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            Road[i][j] = INF;
        }
    }

    scanf("%d %d", &V, &E);
    int preVil;
    int nxtVil;
    int length;
    for (int i = 1; i <= E; i++) {
        scanf("%d %d %d", &preVil, &nxtVil, &length);
        Road[preVil][nxtVil] = length;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            for (int k = 1; k <= V; k++) {
                if (Road[k][j] == INF || Road[i][k] == INF) {
                    continue;
                }
                if (Road[i][j] > Road[i][k] + Road[k][j]) {
                    Road[i][j] = Road[i][k] + Road[k][j];
                }
            }
        }
    }


    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (Road[i][j] != INF && Road[j][i] != INF) {
                if (shortest > Road[i][j] + Road[j][i]) {
                    shortest = Road[i][j] + Road[j][i];
                }
            }
        }
    }

    if (shortest == INF) {
        printf("-1\n");
    }
    else {
        printf("%d", shortest);
    }

    return 0;
}