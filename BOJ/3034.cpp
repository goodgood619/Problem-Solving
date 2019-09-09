#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int n, h, w;
int leng[51];
int main(){
	scanf("%d%d%d", &n, &h, &w);
	int Max = sqrt((h*h) + (w*w));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &leng[i]);
		if (Max >= leng[i]) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}