#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;
typedef int64_t ll;
typedef int32_t ii;
int main() {
	int n;
	scanf("%d", &n);
	ii* dp = new ii[n+1];
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2])% 10;
	printf("%d\n", dp[n]);
	return 0;
}