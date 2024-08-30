#include <stdio.h>

int main() {
	int high;
	int wide;

	scanf("%d %d", &high, &wide);
	getchar();

	char city[high][wide];

	for (int h = 0; h < high; h++) {
		for (int w = 0; w < wide; w++) {
			scanf(" %c", &city[h][w]);
		}
	}

	int cloud[high][wide];
	

	
	for (int h = 0; h < high; h++) {
		for (int w = 0; w < wide; w++) {
			for (int time = 0; time <= w; time++) {
				if (city[h][w-time] == 'c') {
					cloud[h][w] = time;
					break;
				}
				if (time == w) {
					cloud[h][w] = -1;
				}
			}
		}
	}
	

	for (int h = 0; h < high; h++) {
		for (int w = 0; w < wide; w++) {
			printf("%d ", cloud[h][w]);
		}
		printf("\n");
	}

}