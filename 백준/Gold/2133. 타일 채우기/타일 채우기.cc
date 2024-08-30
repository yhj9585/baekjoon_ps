#include <stdio.h>

int N = 0;
int tile[34] = { 0, };

int main() {
	scanf("%d", &N);
    
	tile[1] = 0;
	tile[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		tile[i] += tile[i - 2] * 3;
		for (int j = i - 4; j >= 2; j -= 2) {
			tile[i] += tile[j] * 2;
		}
		tile[i] += 2;
	}

	printf("%d\n", tile[N]);
	return 0;
}