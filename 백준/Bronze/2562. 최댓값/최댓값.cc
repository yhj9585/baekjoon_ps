#include <stdio.h>

int main() {
	int num;
	int point = 0;
	int large = -1;
	for (int i = 1; i < 10; i++) {
		scanf("%d", &num);
		if (num >= large) {
			large = num;
			point = i;
		}
	}
	printf("%d\n%d", large, point);

}