#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int N;
int snum = 0;


char str[100] = { 0, };

int main() {
	scanf("%d", &N);

	int success = 1;
	for (int i = 0; i < N; i++) {
		success = 1;
		snum = 0;

		scanf("%s", str);

		string s(str);

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(') {
				snum++;
			}
			else if (s[j] == ')') {
				if (snum > 0) {
					snum--;
				}
				else {
					printf("NO\n");
					success = 0;
					break;
				}
			}


		}

		if (success == 1 && snum == 0) {
			printf("YES\n");
		}
		else if (success == 1) {
			printf("NO\n");
		}

	}





	return 0;
}