#include <stdio.h>

int main() {
	int score_a = 0, score_b = 0, score_c = 0;
	int score[1000][4];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {

		scanf("%d%d%d", &score[i][1], &score[i][2], &score[i][3]);

		score_a += score[i][1];
		score_b += score[i][2];
		score_c += score[i][3];


	}

	
	if (score_a > score_b && score_a > score_c) {
		printf("1 %d", score_a);
	}
	else if (score_b > score_a && score_b > score_c) {
		printf("2 %d", score_b);
	}
	else if (score_c > score_b && score_c > score_a) {
		printf("3 %d", score_c);
	}
	else {
		int cnt_a3 = 0, cnt_b3 = 0, cnt_c3 = 0;
		int cnt_a2 = 0, cnt_b2 = 0, cnt_c2 = 0;

		for (int i = 0; i < n; i++) {
			if (score[i][1] == 3) {
				cnt_a3++;
			}
			if (score[i][2] == 3) {
				cnt_b3++;
			}
			if (score[i][3] == 3) {
				cnt_c3++;
			}
			if (score[i][1] == 2) {
				cnt_a2++;
			}
			if (score[i][2] == 2) {
				cnt_b2++;
			}
			if (score[i][3] == 2) {
				cnt_c2++;
			}
		}
		

		if (score_a == score_b && score_b > score_c) {
			if (cnt_a3 > cnt_b3) {
				printf("1 %d", score_a);
			}
			else if (cnt_b3 > cnt_a3) {
				printf("2 %d", score_b);
			}
			else if (cnt_a2 > cnt_b2) {
				printf("1 %d", score_a);
			}
			else if (cnt_b2 > cnt_a2) {
				printf("2 %d", score_b);
			}
			else {
				printf("0 %d", score_a);
			}
		}
		else if (score_a < score_b && score_b == score_c) {
			if (cnt_c3 > cnt_b3) {
				printf("3 %d", score_c);
			}
			else if (cnt_b3 > cnt_c3) {
				printf("2 %d", score_b);
			}
			else if (cnt_c2 > cnt_b2) {
				printf("3 %d", score_c);
			}
			else if (cnt_b2 > cnt_c2) {
				printf("2 %d", score_b);
			}
			else {
				printf("0 %d", score_c);
			}
		}
		else if (score_a == score_c && score_b < score_a) {
			if (cnt_a3 > cnt_c3) {
				printf("1 %d", score_a);
			}
			else if (cnt_c3 > cnt_a3) {
				printf("3 %d", score_c);
			}
			else if (cnt_a2 > cnt_c2) {
				printf("1 %d", score_a);
			}
			else if (cnt_c2 > cnt_a2) {
				printf("3 %d", score_c);
			}
			else {
				printf("0 %d", score_a);
			}
		}
		else {
			if (cnt_a3 > cnt_b3 && cnt_a3 > cnt_c3) {
				printf("1 %d", score_a);
			}
			else if (cnt_b3 > cnt_a3 && cnt_b3 > cnt_c3) {
				printf("2 %d", score_b);
			}
			else if (cnt_c3 > cnt_b3 && cnt_c3 > cnt_a3) {
				printf("3 %d", score_c);
			}
			else {
				if (cnt_a3 == cnt_b3 && cnt_a3 > cnt_c3) {
					if (cnt_a2 > cnt_b2) {
						printf("1 %d", score_a);
					}
					else if (cnt_b2 > cnt_a2) {
						printf("2 %d", score_b);
					}
					else {
						printf("0 %d", score_a);
					}
				}
				else if (cnt_a3 == cnt_c3 && cnt_a3 > cnt_b3) {
					if (cnt_a2 > cnt_c2) {
						printf("1 %d", score_a);
					}
					else if (cnt_c2 > cnt_a2) {
						printf("3 %d", score_c);
					}
					else {
						printf("0 %d", score_a);
					}
				}
				else if (cnt_c3 == cnt_b3 && cnt_b3 > cnt_a3) {
					if (cnt_c2 > cnt_b2) {
						printf("3 %d", score_c);
					}
					else if (cnt_b2 > cnt_c2) {
						printf("2 %d", score_b);
					}
					else {
						printf("0 %d", score_b);
					}
				}
				else {
					if (cnt_a2 > cnt_b2 && cnt_a2 > cnt_c2) {
						printf("1 %d", score_a);
					}
					else if (cnt_b2 > cnt_a2 && cnt_b2 > cnt_c2) {
						printf("2 %d", score_b);
					}
					else if (cnt_c2 > cnt_b2 && cnt_c2 > cnt_a2) {
						printf("3 %d", score_c);
					}
					else {
						if (cnt_a2 > cnt_b2 && cnt_a2 == cnt_b2) {
							printf("0 %d", score_a);
						}
						else if (cnt_b2 > cnt_c2&& cnt_b2 == cnt_a2) {
							printf("0 %d", score_a);
						}
						else if (cnt_b2 > cnt_a2&& cnt_b2 == cnt_c2) {
							printf("0 %d", score_b);
						}
						else {
							printf("0 %d", score_a);
						}
					}
				}

			}
		}
	}

}