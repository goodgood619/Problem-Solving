#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1005];
int dp[1005];
int path[1005];
bool visited[1005];
int n;
#define INF 98765432;
void go(int index, int en){
	if (index == 0) return;
	if (path[index] == en){
		go(index - 1, en - 1);
		visited[index] = true;
	}
	else {
		go(index - 1, en);
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = -INF;
	int en = 0;
	for (int i = 1; i <= n; i++) {
		int *idx = lower_bound(dp + 1, dp + en + 1, arr[i]);
		*idx = arr[i];
		path[i] = distance(dp, idx);
		if (idx == dp + en + 1) en++;
	}

	printf("%d\n", en);
	go(n, en);
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
	return 0;
}