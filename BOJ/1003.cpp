#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int dp0[41];
int dp1[41];
int t;
int main(){
	scanf("%d", &t);
	while (t--){
		memset(dp0, 0, sizeof(dp0));
		memset(dp1, 0, sizeof(dp1));
		int n;
		scanf("%d", &n);
		dp0[0] = 1;
		dp1[0] = 0;
		dp0[1] = 0;
		dp1[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp0[i] = dp0[i - 1] + dp0[i - 2];
			dp1[i] = dp1[i - 1] + dp1[i - 2];
		}
		printf("%d %d\n", dp0[n], dp1[n]);
	}
	return 0;
}
