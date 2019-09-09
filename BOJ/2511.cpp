#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10];
int b[10];
int main(){
	for (int i = 0; i < 10;i++)scanf("%d", &a[i]);
	for (int i = 0; i < 10;i++)scanf("%d", &b[i]);
	int asum = 0;
	int bsum = 0;
	int acnt = 0;
	int bcnt = 0;
	bool check = false;
	for (int i = 0; i < 10; i++) {
		if (a[i] < b[i]) { bsum += 3; bcnt++; check = true; }
		else if (a[i] > b[i]) { asum += 3; acnt++; check = false; }
		else { asum += 1;
		bsum += 1;
		}
	}

	printf("%d %d\n", asum, bsum);
	if (asum > bsum) printf("A\n");
	if (asum < bsum) printf("B\n");
	if (asum == bsum && acnt==bcnt){
		if (acnt > 0 && bcnt>0) {
			if (check) printf("B\n");
			else printf("A\n");
		}
		else printf("D\n");
	}
	return 0;
}