#include <stdio.h>
#include <stdlib.h>

int belt[3000003] = {0,};
int cb[3003] = {0,};
    
    

int main() {
 
    int beltN = 0; int cbN = 0; int stream = 0; int coupon = 0;
    scanf("%d %d %d %d", &beltN, &cbN, &stream, &coupon);

    int temp;
    for (int i = 0; i < beltN; i++) {
        scanf("%d", &temp);
        belt[i] = temp;
    }

    int nxtPos = 0;
    int variant = 0; int many = 0; int result = 0;

    while (nxtPos < stream) {
        if (cb[belt[nxtPos]] == 0) {
            variant++;
        }
        cb[belt[nxtPos]] += 1;
        nxtPos++;
    }

    if (cb[coupon] == 0) {
        many = variant + 1;
    }
    else {
        many = variant;
    }
    
    for (int i = 0; i < beltN; i++) {
        if (cb[belt[nxtPos]] == 0) {
            variant++;
        }   
        cb[belt[nxtPos]] += 1;
        nxtPos++;
        if (nxtPos >= beltN) {
            nxtPos -= beltN;
        }
        
        if (cb[belt[i]] == 1) {
            variant--;
        }
        cb[belt[i]] -= 1;

        ///
        if (cb[coupon] == 0) {
            result = variant + 1;
        }
        else {
            result = variant;
        }

        if (result > many) {
            many = result;
        }
    }


    printf("%d\n", many);

    return 0;
}