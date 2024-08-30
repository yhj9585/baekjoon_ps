#include <stdio.h>

int deck[3000] = {0,};
int st = 0;
int ed = 0;

void push(int n) {
    deck[st++] = n;
    return;
}
int pop() {
    return deck[ed++];
}


int main() {

    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        push(i+1);
    }
    int temp;
    for (int i = 0; i < N; i++) {
        printf("%d ", pop());
        temp = pop();
        push(temp);
    }
    return 0;
}