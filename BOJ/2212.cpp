#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k,ans;
int sensor[10005];
int diff[10005];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sensor[i]);
	}
	sort(sensor + 1, sensor + n + 1);
	for (int i = 1; i < n; i++) {
		diff[i] = sensor[i + 1] - sensor[i];
	}
	sort(diff + 1, diff + n);
	for (int i = 1; i <= n - k; i++){ // diff중에서 가장 긴 거리 k-1개를 빼면 됨, 반대로, 1부터 n-k까지 더하면됨 
		ans += diff[i];
	}
	printf("%d\n", ans);
	return 0;
}