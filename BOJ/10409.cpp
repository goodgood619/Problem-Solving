#include <stdio.h>
#include <algorithm>
using namespace std;
int n, t,sum,cnt;
int work[51];
int main(){
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) scanf("%d", &work[i]);
	for (int i = 1; i <= n; i++) {
		sum += work[i];
		if (sum <= t) {
			cnt++;
			continue;
		}
		else break;
	}
	printf("%d\n", cnt);
	return 0;
}