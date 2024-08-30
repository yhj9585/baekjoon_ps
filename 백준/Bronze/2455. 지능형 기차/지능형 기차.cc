#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    
	int in, out;
	int people = 0;
	int large = -1000001;
    
	for (int i = 1; i < 5; i++) {
		scanf("%d%d", &out, &in);
		people += in;
		people -= out;
		if (people > large) {
			large = people;
		}
	}
	printf("%d", large);
}