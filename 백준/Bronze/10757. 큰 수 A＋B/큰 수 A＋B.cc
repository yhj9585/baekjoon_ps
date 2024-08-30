#include <stdio.h>

int start[10005] = {0,};
int numA[10005] = {0,};
int numB[10005] = {0,};
int lngA = 0;
int lngB = 0;
int added[10005] = {0,};

// -48 = 0 , 49 50 51 52 53 54 55 56 57 = 9

int main() {

    char temp = 'a';
    while (temp != ' ') {
        scanf("%1c", &temp);
        if ((int)temp > 57 || (int)temp < 48) break;
        else {
            start[lngA++] = (int)temp - 48;
        }
    }

   for (int i = 0; i <= lngA; i++) {
        numA[i] = start[lngA-i-1];
    }

    temp = 'a';
    while (temp != '\n') {
        scanf("%1c", &temp);
        if ((int)temp > 57 || (int)temp < 48) break;
        else {
            start[lngB++] = (int)temp - 48;
        }
    }

    for (int i = 0; i <= lngB; i++) {
        numB[i] = start[lngB-i-1];
    }

    int larger;
    if (lngA > lngB) {
        larger = lngA;
    }
    else {
        larger = lngB;
    }

    int over = 0;
    if (numA[0]+numB[0] > 9) {
        over = 1;
    }
    added[0] = (numA[0]+numB[0])%10;

    for (int i = 1; i <= larger; i++) {
        added[i] = (numA[i]+numB[i]+over)%10;
        if (numA[i]+numB[i]+over>9) {
            over = 1;
        }
        else {
            over = 0;
        }
    }

    if (added[larger] != 0) {
        printf("%d", added[larger]);
    }
    for (int i = 1; i <= larger; i++) {
        printf("%d", added[larger-i]);
    }
    printf("\n");
    
    return 0;
}