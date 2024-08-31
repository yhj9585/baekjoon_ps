#pragma warning (disable:4996)

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N;

typedef struct point {
	int N;
	vector<pair<int, int>> lines;
}point;

vector<point> tree;

int largest;

int chk[100010] = { 0, };
int bfs(int startpoint) {
	queue<pair<int, int>> que;

	memset(chk, 0, sizeof chk);

	int nxtpos;
	int nxtdist;

	chk[startpoint] = -1;
	que.push(make_pair(startpoint, 0));
	while (que.size() != 0) {
		auto nowpos = que.front();
		que.pop();

		for (int i = 0; i < tree[nowpos.first].lines.size(); i++) {

			nxtpos = tree[nowpos.first].lines[i].first;
			nxtdist = tree[nowpos.first].lines[i].second + nowpos.second;

			if (chk[nxtpos] == 0) {
				chk[nxtpos] = nxtdist;

				que.push(make_pair(nxtpos, nxtdist));
			}
		}
	}

	largest = 0; 
	int farPoint = startpoint;
	for (int i = 1; i <= N; i++) {
		if (chk[i] > largest) {
			largest = chk[i];
			farPoint = i;
		}
	}

	return farPoint;
}

int main() {
	int temp;
	int temp2;

	scanf("%d", &N);

	tree.resize(N+10);

	int point;
	for (int i = 0; i < N; i++) {
		scanf("%d", &point);

		tree[point].N = point;

		temp = 0;
		while (temp != -1) {
			scanf("%d", &temp);

			if (temp == -1) {
				break;
			}
			else {
				scanf("%d", &temp2);

				tree[point].lines.push_back(make_pair(temp, temp2));
			}
		}
	}

	bfs(bfs(1));
	
	printf("%d\n", largest);

	return 0;
}