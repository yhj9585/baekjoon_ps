#include <stdio.h>
#pragma warning(disable:4996)

int N;

struct pixel {
	int zip;
	int data;
	pixel* Lu;
	pixel* Ru;
	pixel* Ld;
	pixel* Rd;
};

pixel display[7][64][64];

int pixelTest(int lv, int i, int j) {

	if (display[lv][i][j].zip == 0 || display[lv][i + 1][j].zip == 0 || display[lv][i][j + 1].zip == 0 || display[lv][i + 1][j + 1].zip == 0) {
		return 0;
	}

	if (display[lv][i][j].data == display[lv][i][j + 1].data) {
		if (display[lv][i][j + 1].data == display[lv][i + 1][j].data) {
			if (display[lv][i + 1][j].data == display[lv][i + 1][j + 1].data) {
				return 1;
			}
		}
	}
	return 0;
}


void quadTree(int leng, int lv) {

	for (int i = 0; i < leng; i++) {
		for (int j = 0; j < leng; j++) {

			if (pixelTest(lv, i, j)) {
				display[lv + 1][i / 2][j / 2].zip = 1;
				display[lv + 1][i/2][j/2].data = display[lv][i][j].data;
			}
			else {
				display[lv + 1][i / 2][j / 2].zip = 0;
				display[lv + 1][i / 2][j / 2].Lu = &display[lv][i][j];
				display[lv + 1][i / 2][j / 2].Ru = &display[lv][i][j+1];
				display[lv + 1][i / 2][j / 2].Ld = &display[lv][i+1][j];
				display[lv + 1][i / 2][j / 2].Rd = &display[lv][i+1][j+1];
			}	
			j++;
		}
		i++;
	}
}

void printTree(pixel* nPixel) {

	if (nPixel->zip == 1) {
		printf("%d", nPixel->data);
	}
	else {
		printf("(");
		printTree(nPixel->Lu);
		printTree(nPixel->Ru);
		printTree(nPixel->Ld);
		printTree(nPixel->Rd);
		printf(")");
	}


}

int main() {

	scanf("%d", &N);

	int dat;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &dat);
			display[0][i][j].zip = 1;
			display[0][i][j].data = dat;
		}
	}

	int i = 0;
	int widN = N;

	while (widN > 1) {
		quadTree(widN, i);
		widN /= 2;
		i++;
	}

	pixel* now = &display[i][0][0];

	printTree(now);

	return 0;
}
