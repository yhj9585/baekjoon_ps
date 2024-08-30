#include <stdio.h>
#include <stdlib.h>

int N;
int answer = 0;

int col[16]  = {0,};
int cro1[31] = {0,};
int cro2[31] = {0,};

void dfs(int depth) {
    if (depth == N) {
        answer++;
        return;
    }

    for(int i = 0; i < N; i++) {
        if (col[i] == 0 && cro1[i+depth] == 0 && cro2[i-depth+N] == 0) {
            col[i] = 1;
            cro1[i+depth] = 1;
            cro2[i-depth+N] = 1;
            dfs(depth+1);
            col[i] = 0;
            cro1[i+depth] = 0;
            cro2[i-depth+N] = 0;
        }
    }

}

int main() {
	scanf("%d", &N);
    dfs(0);
    printf("%d", answer);
    return 0;
}
