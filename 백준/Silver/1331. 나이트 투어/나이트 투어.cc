 #include <stdio.h>

int map[7][7] = {0,};

int move[8][2] = {
    {-2,  1},
    {-2, -1},
    {-1,  2},
    {-1, -2},
    { 1,  2},
    { 1, -2},
    { 2,  1},
    { 2, -1}
};


 int main() {
    int valid = 1;
    int result = 1;
    char temp;
    int firx;
    int firy;
    int posy;
    int posx;
    int prex;
    int prey;

    // 첫번째 칸
    scanf("%c%d", &temp, &prey);
    prex = (int)temp - 65; // A = 0~
    prey--;
    firx = prex;
    firy = prey;
    map[prey][prex] = 1;
    getchar();

    for (int i = 1; i < 36; i++) {
        scanf("%c%d", &temp, &posy);
        posx = (int)temp - 65; // A = 0~
        posy--;
        
        if (map[posy][posx] == 1) {
            result = 0;
        }
        else {
            map[posy][posx] = 1;
        }

        for (int j = 0; j < 8; j++) {
            if (posx + move[j][1] == prex && posy + move[j][0] == prey) {
                valid = 1;
                break;
            }
            valid = 0;
        }
        if (valid == 0) {
            result = 0;
        }
        
        prex = posx;
        prey = posy;
        getchar();
    }

    for (int j = 0; j < 8; j++) {
        if (firx + move[j][1] == prex && firy + move[j][0] == prey) {
            valid = 1;
            break;
        }
        valid = 0;
    }
    if (valid == 0) {
        result = 0;
    }    

    if (result == 1) {
        printf("Valid\n");
    }
    else {
        printf("Invalid\n");
    }

    return 0;
 }