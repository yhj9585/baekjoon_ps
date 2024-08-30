#include <stdio.h>

int map[5][5] = {0,};

typedef struct pos {
    int y;
    int x;
    int dir;
    int life;
}pos;

pos shark[20];
const int Nshark = 50;

pos fishes[20][20];

int move[9][2] = {
    { 0, 0}, // FROM UP TO 45' Degree CounterclockWise
    {-1, 0},
    {-1,-1},
    { 0,-1},
    { 1,-1},
    { 1, 0},
    { 1, 1},
    { 0, 1},
    {-1, 1}
};

int eatsize = 0;
int most = 0;

void pri() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d", map[i][j]);
        }
        printf("\n");
    }
    //printf("\n");
}

int fshchk(pos fishTo) {
    if (fishTo.y >= 4 || fishTo.y < 0 || fishTo.x >= 4 || fishTo.x < 0) { // OUT OF BOUND
        return 0;
    }
    else if (map[fishTo.y][fishTo.x] == Nshark){ // SHARK!!!!
        return 0;
    }
    else if (map[fishTo.y][fishTo.x] == 0) { // NOTHING
        return 2;
    }
    else { // CHANGE WITH OTHER FISH
        return 1;
    }
}

void fishmove(int depth) {
    pos nxtfish;
    int nxtrot;
    int changeWith;

    for (int i = 1; i <= 16; i++) {
        if (fishes[depth+1][i].life != 0){
            for (int rot = 0; rot < 8; rot++) { // ROTATION CHK
                if (fishes[depth+1][i].dir + rot >= 9) {
                    nxtrot = fishes[depth+1][i].dir + rot - 8;
                }
                else {
                    nxtrot = fishes[depth+1][i].dir + rot;
                }

                // NXT POS
                nxtfish.y = fishes[depth+1][i].y + move[nxtrot][0];
                nxtfish.x = fishes[depth+1][i].x + move[nxtrot][1];
                nxtfish.dir = nxtrot;

                if (fshchk(nxtfish) == 1) { // CHANGE WITH FISH
                    changeWith = map[nxtfish.y][nxtfish.x];
                    fishes[depth+1][changeWith].y = fishes[depth+1][i].y;
                    fishes[depth+1][changeWith].x = fishes[depth+1][i].x;
                    fishes[depth+1][changeWith].dir = fishes[depth+1][changeWith].dir;

                    // MAP CHANGE
                    map[fishes[depth+1][i].y][fishes[depth+1][i].x] = changeWith;
                    map[nxtfish.y][nxtfish.x] = i;

                    fishes[depth+1][i].y = nxtfish.y;
                    fishes[depth+1][i].x = nxtfish.x;
                    fishes[depth+1][i].dir = nxtfish.dir;
                    break;
                }
                else if (fshchk(nxtfish) == 2) { // Move to EMpty
                    map[fishes[depth+1][i].y][fishes[depth+1][i].x] = 0;
                    fishes[depth+1][i].y = nxtfish.y;
                    fishes[depth+1][i].x = nxtfish.x;
                    fishes[depth+1][i].dir = nxtfish.dir;
                    map[nxtfish.y][nxtfish.x] = i;
                    break;
                }
                else { // CAN't mOVE
                    continue;
                }
            }

        }
        //printf("Move : %d\n", i);
        //pri();
    }
    return;
}

void mapUpdate(int depth, int typ) {
    for (int i = 0; i < 4; i++) { // RESET
        for (int j = 0; j < 4; j++) {
            map[i][j] = 0;
        }
    }
    
    
    for (int i = 1; i <= 16; i++) { // FISH UPDATE
        if (fishes[depth][i].life != 0) {
            map[fishes[depth][i].y][fishes[depth][i].x] = i;
        }
    }

    // SHARK UPDATE
    
    map[shark[depth-typ].y][shark[depth-typ].x] = Nshark;

    //pri();
}

int shkchk(pos sharkTo) {
    if (sharkTo.y >= 4 || sharkTo.y < 0 || sharkTo.x >= 4 || sharkTo.x < 0) { // OUT OF BOUND
        return 0;
    }
    else if (map[sharkTo.y][sharkTo.x] == 0) { // NOTHING
        return 2;
    }
    else { // FISH TO EAT
        return 1;
    }
    
}

void simul(int depth) {
    //printf("Time : %d\n", depth);
    mapUpdate(depth,0); // UPDATE SHARK

    for (int i = 1; i <= 16; i++) {
        fishes[depth+1][i] = fishes[depth][i];
    }

    fishmove(depth);
    
    //printf("\n");
    pos nowpos;
    pos nxtpos;
    int fishToeat;

    nowpos = shark[depth];

    for (int i = 1; i <= 3; i++) { // GO STRAIGHT SHARK to 3
        //printf("Time:%d, Go:%d\n", depth, i);
        mapUpdate(depth+1, 1);
        nxtpos.y = nowpos.y + move[nowpos.dir][0]*i;
        nxtpos.x = nowpos.x + move[nowpos.dir][1]*i;
        if (shkchk(nxtpos) == 1) { // FISH to EAT
            fishToeat = map[nxtpos.y][nxtpos.x];
            fishes[depth+1][fishToeat].life = 0;
            nxtpos.dir = fishes[depth+1][fishToeat].dir;
            eatsize += fishToeat;
            shark[depth+1] = nxtpos;
            map[nxtpos.y][nxtpos.x] = Nshark;
            simul(depth+1);
            eatsize -= fishToeat;
            map[nxtpos.y][nxtpos.x] = fishToeat;
            fishes[depth+1][fishToeat].life = 1;
        }
        else if (shkchk(nxtpos) == 2) { // NOTHING
            continue;
        }   
        else { // Out OF BOUND
            //printf("BREAK dir:%d\n", nowpos.dir);
            break;
        }
    }

    if (eatsize > most) {
        most = eatsize;
    }

    return;
}

int main() {
    int tempdir;
    int tempfish;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d %d", &map[i][j], &tempdir);
            tempfish = map[i][j];
            fishes[0][tempfish].y = i;
            fishes[0][tempfish].x = j;
            fishes[0][tempfish].dir = tempdir;
            fishes[0][tempfish].life = 1;
        }
    }
    shark[0].y = 0;
    shark[0].x = 0;
    shark[0].dir = fishes[0][map[0][0]].dir;
    fishes[0][map[0][0]].life = 0;
    eatsize = map[0][0];
    
    simul(0);
    printf("%d\n", most);

    return 0;
}