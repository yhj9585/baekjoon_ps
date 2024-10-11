#pragma warning (disable:4996)
#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> que;

char cha[10];

int main() {
	scanf("%d", &N);

	string s; 
	int in = 0;
	int out = 0;
	for (int i = 0; i < N; i++) {
		scanf("%s", cha);
		s = string(cha);

		if (s == "push") {
			scanf("%d", &in);
			que.push(in);
		}
		else if (s == "pop") {
			if (que.empty() == 1) {
				printf("-1\n");
			}
			else {
				out = que.front(); que.pop();
				printf("%d\n", out);
			}
		}
		else if (s == "front") {
			if (que.empty() == 1) {
				printf("-1\n");
			}
			else {
				out = que.front();
				printf("%d\n", out);
			}
		}
		else if (s == "back") {
			if (que.empty() == 1) {
				printf("-1\n");
			}
			else {
				out = que.back();
				printf("%d\n", out);
			}
		}
		else if (s == "size") {
			printf("%d\n", que.size());
		}
		else if (s == "empty") {
			printf("%d\n", que.empty());
		}
	}



	return 0;
}