#include <stdio.h>
#include <string.h>

int map[10][10] = {0,};
typedef struct pos {
    int y;
    int x;
}pos;

pos k_pos;
pos s_pos;

int N;

int chk(pos nxtpos) {
    if (nxtpos.y >= 8 || nxtpos.y < 0 || nxtpos.x >= 8 || nxtpos.x < 0) {
        return 1;
    }
    if (nxtpos.y == s_pos.y && nxtpos.x == s_pos.x) {
        return 2;
    }
    
    return 0;
}




int main() {

    char tempC;
    int tempI;
    scanf("%1c%1d", &tempC, &tempI);

    k_pos.y = 8 - tempI;
    k_pos.x = (int)tempC - 65;

    scanf(" %1c%1d", &tempC, &tempI);

    s_pos.y = 8 - tempI;
    s_pos.x = (int)tempC - 65;

    scanf("%d", &N);

    pos nxtmove = {0, 0};
    pos nxtpos = {0,0};
    pos Snxtpos = {0,0};

    char str[5];
    for (int i = 0; i < N; i++) {

        nxtpos.x = k_pos.x;
        nxtpos.y = k_pos.y;

        nxtmove.x = 0;
        nxtmove.y = 0;
        
        scanf("%s", str);

        if (str[0] == 'L') {
            nxtmove.x = -1;
        }
        if (str[0] == 'R') {
            nxtmove.x = 1;
        }
        if (str[0] == 'T' || str[1] == 'T') {
            nxtmove.y = -1;
        }
        if (str[0] == 'B' || str[1] == 'B'){
            nxtmove.y = 1;
        }

        nxtpos.x += nxtmove.x;
        nxtpos.y += nxtmove.y;

        if (chk(nxtpos) == 1) {
            continue;
        }
        else if (chk(nxtpos) == 2) {
            Snxtpos.x = s_pos.x + nxtmove.x;
            Snxtpos.y = s_pos.y + nxtmove.y;
            if (chk(Snxtpos) == 1) {
                continue;
            }
            s_pos.y = Snxtpos.y;
            s_pos.x = Snxtpos.x;
        }

        k_pos.y = nxtpos.y;
        k_pos.x = nxtpos.x;
        
        //printf("%c%d\n", (char)(k_pos.x + 64), 8 - k_pos.y);
    }

    printf("%c%d\n", (char)(k_pos.x + 65), 8 - k_pos.y);
    printf("%c%d\n", (char)(s_pos.x + 65), 8 - s_pos.y);

    return 0;
}
