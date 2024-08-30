#pragma warning(disable:4996)

#include <iostream>
#include <set>
#include <queue>

using namespace std;

int N; int K;

priority_queue<pair<int, int>> gem;
multiset<int> back;

long long answer = 0;

int lightest = 1999999999;

int main() {
	scanf("%d %d", &N, &K);

	int temp1; int temp2;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &temp1, &temp2);
		gem.push(make_pair(temp2, temp1));

		if (temp1 < lightest) {
			lightest = temp1;
		}
	}

	for (int i = 0; i < K; i++) {
		scanf("%d", &temp1);
		back.insert(temp1);
	}


	while (gem.size() != 0 && back.size() != 0) {
		auto nowgem = gem.top();
		gem.pop();

		auto nowback = back.lower_bound(nowgem.second);

		if (nowback != back.end()) {
			answer += nowgem.first;
			back.erase(nowback);
		}
		else {
			if (nowgem.second == lightest) {
				break;
			}
		}


	}

	printf("%lld\n", answer);

	return 0;
}