#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1003];
int dp[1003];
int n,en;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]);}
	for (int i = 1; i <= n; i++) {
		int *idx = lower_bound(dp + 1, dp + en + 1, arr[i]);
		*idx = arr[i];
		if (idx == dp + en + 1) { en++; }
	}
	printf("%d\n", en);
	return 0;
}