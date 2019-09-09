#include <cstdio>
#include <algorithm>
using namespace std;
int n,Max;
int arr[1003];
int dp[1003];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}
	Max = dp[1];
	for (int i = 2; i <= n; i++){
		for (int j = 1; j < i; j++) {
			if (arr[j]<arr[i]) {
				dp[i] = max(dp[i], arr[i] + dp[j]);
			}
		}
		Max = max(dp[i], Max);
	}
	printf("%d\n", Max);
	return 0;
}