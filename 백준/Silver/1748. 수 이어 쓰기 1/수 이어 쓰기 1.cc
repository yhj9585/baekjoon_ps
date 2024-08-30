#include<stdio.h>

long long N;

int main()

{

    scanf("%d", &N);

    int answer;

    

    int tmp;

    tmp = 10;

    answer = N;

    

    while (N > tmp-1) {

        answer += (N - (tmp-1));

        tmp*=10;

    }

    

    

    printf("%d", answer);

    

    return 0;

}