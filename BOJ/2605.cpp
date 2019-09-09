#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[110];
int dp[110];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = i;
		int temp2 = i;
		for (int j = 0; j < arr[i]; j++) {
			int temp = dp[temp2];
			dp[temp2] = dp[temp2-1];
			dp[temp2-1] = temp;
			temp2--;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", dp[i]);
	return 0;
}