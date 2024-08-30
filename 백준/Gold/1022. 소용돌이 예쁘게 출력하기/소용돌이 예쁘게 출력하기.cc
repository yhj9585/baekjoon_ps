#include <stdio.h>
#include <math.h>

int value(int i, int j) {
    
    int n = abs(i)> abs(j) ? abs(i): abs(j);
    int val = (2 * n + 1)*(2*n+1);


    if (i == n) {
        return val - (n - j);
    }
    val -= 2*n;
    
    if (j == -n) {
        return val - (n - i);
    }
    val -= 2*n;
    
    if (i == -n) {
        return val - (j + n);
    }
    val -= 2*n;
    
    return val - (i + n);
}


int main() {
    int r1, c1, r2, c2,max=0;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    int len = 0;
    max = value(r1,c1)>max?value(r1,c1):max;
	max = value(r1,c2)>max?value(r1,c2):max;
	max = value(r2,c1)>max?value(r2,c1):max;
	max = value(r2,c2)>max?value(r2,c2):max;
			
		
	while(max){
		max/=10;
		len++;
	}
    
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
			printf("%*d ", len, value(i, j));
        }
        printf("\n");
    }

}