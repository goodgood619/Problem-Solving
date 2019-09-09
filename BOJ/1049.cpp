#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m;
int Min = 999999;
int six[51];
int one[51];
int ans,small;
int sixsmall=999999;
int onesmall = 999999;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) 
		scanf("%d%d", &six[i], &one[i]);
	for (int i = 1; i <= m; i++)
		sixsmall=min(six[i], sixsmall);
	for (int i = 1; i <= m; i++)
		onesmall = min(one[i], onesmall);
	while (n > 0) {
		if (n > 0 && n <= 6) {
			Min = min(Min, sixsmall);
			Min = min(Min, onesmall * n);
			ans += Min;
			n -= 6;
		}
		else if(n>6){
			small = min(sixsmall, onesmall * 6);
			ans += small;
			n -= 6;
		}
	}
	printf("%d\n",ans);
	return 0;
}