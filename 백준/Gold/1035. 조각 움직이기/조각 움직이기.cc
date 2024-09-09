#pragma warning (disable:4996)

using namespace std;

#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <cmath>

int board[6][6] = { 0, };
int orgmap[6][6] = { 0, };

int chk[6][6] = { 0, };

unordered_map<int, int> hashmap;
queue<pair<int, int>> que;

typedef struct node {
	short pos[5][2];
	int depth;
};

int moveR[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

queue<node> que2;

int numblock;
node blockpos = { 0, };

int hashmake() {
	int num = 0;
	int s = 1;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == 1) {
				num += s;
			}
			s *= 2;
		}
	}

	return num;
}

int check(pair<int, int> nxtpos) {
	if (nxtpos.first >= 5 || nxtpos.second >= 5 || nxtpos.first < 0 || nxtpos.second < 0) {
		return 0;
	}
	if (chk[nxtpos.first][nxtpos.second] != 0) {
		return 0;
	}
	if (board[nxtpos.first][nxtpos.second] == 0) {
		return 0;
	}
	return 1;
}

int check2(node nxt, int i, int map[][6]) {
	if (nxt.pos[i][0] >= 5 || nxt.pos[i][1] >= 5 || nxt.pos[i][0] < 0 || nxt.pos[i][1] < 0) {
		return 0;
	}
	if (map[nxt.pos[i][0]][nxt.pos[i][1]] != 0) {
		return 0;
	}

	// Hash make
	int num = 0;
	for (int j = 0; j < numblock; j++) {
		num += pow(2, nxt.pos[j][0] * 5 + nxt.pos[j][1]);
	}
	if (hashmap[num] != 0) {
		return 0;
	}
	else {
		hashmap[num] = 1;
		return 1;
	}

}

int moveable() {
	int size = 1;

	while (que.size() != 0) {
		auto nowpos = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			auto nxtpos = make_pair(nowpos.first + moveR[i][0], nowpos.second + moveR[i][1]);

			if (check(nxtpos) == 1) {
				size++;
				chk[nxtpos.first][nxtpos.second] = 1;
				que.push(nxtpos);
				if (size == numblock) {
					return size;
				}
			}
			else {
				continue;
			}
		}
	}
	return size;
}

int moveblock() {
	int nowmap[6][6] = { 0, };
	int tempmap[6][6] = { 0, };
	
	while (que2.size() != 0) {
		memset(nowmap, 0, sizeof nowmap);
		auto now = que2.front();
		que2.pop();

		for (int i = 0; i < numblock; i++) {
			nowmap[now.pos[i][0]][now.pos[i][1]] = 1;
		}

		for (int i = 0; i < numblock; i++) {
			for (int j = 0; j < 4; j++) {
				auto nxt = now;
				nxt.depth++;
				nxt.pos[i][0] += moveR[j][0];
				nxt.pos[i][1] += moveR[j][1];
				
				if (check2(nxt, i, nowmap) == 1) {
					que2.push(nxt);

					que = queue<pair<int, int>>();
					memset(chk, 0, sizeof chk);
					memset(board, 0, sizeof board);

					chk[nxt.pos[i][0]][nxt.pos[i][1]] = 1;
					que.push(make_pair(nxt.pos[i][0], nxt.pos[i][1]));


					for (int a = 0; a < numblock; a++) {
						board[nxt.pos[a][0]][nxt.pos[a][1]] = 1;
					}

					if (moveable() == numblock) {
						return nxt.depth;
					}


				}
			}
		}
	}
}

int main() {
	char temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%1c", &temp);
			if (temp == '.') {
				orgmap[i][j] = 0;
			}
			else {
				orgmap[i][j] = 1;
				blockpos.pos[numblock][0] = i;
				blockpos.pos[numblock][1] = j;
				numblock++;
			}
		}
		getchar();
	}

	if (numblock == 1) {
		printf("0\n");
		return 0;
	}

	memcpy(board, orgmap, sizeof orgmap);

	for (int i = 0; i < numblock; i++) {
		memset(chk, 0, sizeof chk);
		chk[blockpos.pos[i][0]][blockpos.pos[i][1]] = 1;
		que = queue<pair<int, int>>();
		que.push(make_pair(blockpos.pos[i][0], blockpos.pos[i][1]));

		if (moveable() == numblock) {
			printf("0\n");
			return 0;
		}
	}

	int nowh = hashmake();
	hashmap[nowh] = 1;

	blockpos.depth = 0;
	que2.push(blockpos);
	printf("%d\n", moveblock());

	return 0;
}