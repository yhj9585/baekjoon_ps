#include <stdio.h>

int N; // 로봇이 내리는 칸
int K; // 내구도 일정 이하인 칸 갯수 제한 


typedef struct node {
    int rob;
    int durable;
    int used;
}node;

node belt[202] = {0,};



int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= 2*N; i++) {
        scanf("%d", &belt[i].durable);
    }

    int spos = 1;
    int epos = N;

    int brokenN = 0;
    int level = 0;

    while (brokenN < K) {
        level++;
        spos--;
        epos--;

        if (spos == 0) {
            spos = 2*N;
        }
        if (epos == 0) {
            epos = 2*N;
        }

        if (belt[epos].rob != 0) {
            belt[epos].rob = 0;
        }

        int i = epos;
        while (i != spos) {
            i--;
            if (i == 0) {
                i = 2*N;
            }
            if (belt[i].rob != 0) {
                if (i != 2*N) {
                    if (belt[i+1].rob == 0 && belt[i+1].used != belt[i+1].durable) {
                        belt[i+1].rob = belt[i].rob;
                        belt[i+1].used += 1;
                        if (belt[i+1].durable == belt[i+1].used) {
                            brokenN++;
                        }
                        belt[i].rob = 0;
                    }
                }
                else {
                    if (belt[1].rob == 0 && belt[1].used != belt[1].durable) {
                        belt[1].rob = belt[i].rob;
                        belt[1].used += 1;
                        if (belt[1].durable == belt[1].used) {
                            brokenN++;
                        }
                        belt[i].rob = 0;
                    }                    
                }
            }
        }

        if (belt[epos].rob != 0) {
            belt[epos].rob = 0;
        }

        if (belt[spos].durable != belt[spos].used) {
            belt[spos].rob = level;
            belt[spos].used += 1;
            if (belt[spos].durable == belt[spos].used) {
                brokenN++;
            }
        }

        if (brokenN >= K) {
            break;
        }


    }


    printf("%d\n", level);

    return 0;
}