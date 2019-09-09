#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[105];
int check[105];
int t;
int main(){
	scanf("%d", &t);
	while (t--){
		memset(check, 0, sizeof(check));
		memset(dp, 0, sizeof(dp));
		int n;
		scanf("%d", &n);
		dp[1] = n;
		for (int i = 1; i <= n; i++) { check[i] = 1;}
		for (int j = 2; j <= n; j++){
			int cnt = 0;
			for (int i = j; i <= n; i+=j){
				if (check[i]) check[i] = 0;
				else check[i] = 1;
			}
			for (int i = 1; i <= n; i++) {
				if (check[i]) cnt++;
				else continue;
			}
			dp[j] = cnt;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}