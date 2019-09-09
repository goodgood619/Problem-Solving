#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
typedef pair <int, int> P;
P eat[500005];
int dp[500005];
bool visited[500005];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int index, left, right;
		scanf("%d%d%d", &index, &left, &right);
		eat[index].first = left;
		eat[index].second = -right;
	}
	sort(eat + 1, eat + n + 1);
	for (int i = 1; i <= n-1; i++) {
		int first = eat[i].first;
		int second = eat[i].second;
		int nextfirst = eat[i+1].first;
		int nextsecond = eat[i+1].second;
		if (first == nextfirst && second == nextsecond) visited[i] = true;
	}
	dp[0] = -98765432;
	int en = 0;
	for (int i = n; i>=1; i--){
		if (visited[i]) continue;
		int *idx = upper_bound(dp + 1, dp + en + 1, abs(eat[i].second));
		*idx = abs(eat[i].second);
		if (idx == dp + en + 1) en++;
	}
	printf("%d\n",  en);
	return 0;
}