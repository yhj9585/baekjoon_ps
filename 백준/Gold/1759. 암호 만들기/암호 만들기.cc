#include <stdio.h>
#pragma warning(disable : 4996)

#define N 1000

// QUEUE //
int tp = 0;

char queue[N] = { 0, };

void push(char a) {
    queue[tp++] = a;
}

void pop() {
    tp--;
}

int top() {
    return queue[tp];
}

void printStack() {
    for (int i = 0; i < tp; i++) {
        printf("%c", queue[i]);
    }
    printf("\n");
}

char cha[N] = { 0, };
int test[N] = { 0, };
int num = 0;
int charN = 0;

int valid() {
    // 모음 테스트 //
    int m = 0, j = 0;
    for (int i = 0; i < num; i++) {
        if (queue[i] == 'a' || queue[i] == 'e' || queue[i] == 'o' || queue[i] == 'u' || queue[i] == 'i') {
            m = 1;
            break;
        }
    }


    // 자음 테스트 //
    for (int i = 0; i < num; i++) {
        if (queue[i] != 'a' && queue[i] != 'e' && queue[i] != 'o' && queue[i] != 'u' && queue[i] != 'i') {
            j++;
        }
        if (j == 2) {
            break;
        }
    }

    if (m == 1 && j == 2) {
        return 1;
    }
    else {
        return 0;
    }

}


void dfs(int round, int nPos) {



    if (test[nPos] == 1) return;
    push(cha[nPos]);
    test[nPos] = 1;

    if (tp != num) {
        for (int n = nPos; n < charN; n++) {
            dfs(round + 1, n);
        }
    }
 


    if (tp == num && valid() == 1) {
        printStack();
    }

    test[nPos] = 0;
    pop();
}



int main() {
    scanf("%d %d", &num, &charN);



    for (int i = 0; i < charN; i++) {
        scanf(" %c", &cha[i]);
    }

    char temp;
    for (int i = 0; i < charN; i++) {
        for (int j = i; j < charN; j++) {
            if (cha[i] > cha[j]) {
                temp = cha[i];
                cha[i] = cha[j];
                cha[j] = temp;
            }
        }
    }
   
    for (int a = 0; a < charN; a++) {
        dfs(1, a);
    }

 }