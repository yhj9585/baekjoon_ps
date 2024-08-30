#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N; int M;
int bothN = 0;

void binarySearch(char** notHear, char** notHearSee, char* Now) {
    int mid;
    int right = N-1;
    int left = 0;

    while(left <= right) {
        mid = (left+right)/2;

        if (strcmp(notHear[mid], Now) > 0) {
            right = mid-1;
        }
        else if (strcmp(notHear[mid], Now) < 0) {
            left = mid+1;
        }
        else {
            strcpy(notHearSee[bothN++],Now);
            break;
        }
    }
    return;
}

int compare(const void* a, const void* b) {
    char* string1;
    char* string2;
    string1 = *(char**)a;
    string2 = *(char**)b;

    if (strcmp(string1, string2)>0) {
        return 1;
    }
    else if (strcmp(string1, string2) <0) {
        return -1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &M);
    char** notHear;
    char** notHearSee;

    notHear = (char**)calloc((long long unsigned int)N,sizeof(char*));
    notHearSee = (char**)calloc((long long unsigned int)N,sizeof(char*));

    for (int i = 0; i < N; i++) {
        notHear[i] = (char*)calloc(20, sizeof(char));
        notHearSee[i] = (char*)calloc(20, sizeof(char));
    }

    for (int i = 0; i < N; i++) {
        scanf("%s", notHear[i]);
    }

    qsort(notHear, (long long unsigned int)N, sizeof(notHear[0]), compare);

    char newString[20] = {0,};
    for (int i = 0; i < M; i++) {
        scanf("%s", newString);
        binarySearch(notHear, notHearSee, newString);
    }

    printf("%d\n", bothN);
    if (bothN != 0) {
        qsort(notHearSee, (long long unsigned int)bothN, sizeof(notHearSee[0]), compare);
    
        for(int i = 0; i < bothN; i++) {
            printf("%s\n", notHearSee[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        free(notHear[i]);
        free(notHearSee[i]);
    }

    free(notHear);
    free(notHearSee);

    return 0;
}