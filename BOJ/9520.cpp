#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1501][1501];
int arr[1501][1501];
int n;
int func(int x, int y, int num){
	// n까지인데 n+1이면 더이상 갈필요가 없
	if (num == n + 1)
		return 0;
	int& ref = dp[x][y];
	if (ref != -1)
		return ref;
	int left = func(num, y, num + 1) + arr[x][num]; // 왼쪽에다가 붙일건지(num+1을)
	int right = func(x, num, num + 1) + arr[y][num]; // 오른쪽에다가 붙일건지(num+1을)
	return ref = min(left, right); // 왼쪽에 붙이건 오른쪽에 붙이건, 매번 최소값만을 반환해준다.
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &arr[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d", func(1, 1, 1));
	return 0;
}