#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
Int dp[21][21];
void go(int n) {
	for (int j = 1; j < n; j++) {
		if (j % 2 && n-j<3) {
			dp[n][j] += dp[n - 1][j];
		}
		else if (j%2 == 0 && n - j < 4) {
			dp[n][j] += dp[n - 1][j];
		}
		dp[n][n] += dp[n - 1][j];
	}
}
int main() {
	dp[1][1] = 1;
	for (int i = 2; i <= 20; i++) {
		go(i);
	}
	Int n,sum=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		sum += dp[n][i];
	}
	printf("%d\n", sum);
	return 0;
}