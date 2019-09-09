#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
P anspo[100005];
int real[100005];
int dp[100005];
int n;
int p = 1;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		anspo[i].first = first;
		anspo[i].second = second;
	}
	for (int i = n; i >= 1; i--) {
		real[p++] = anspo[i].second;
	}
	
	int group = n;
	int curspeed = real[1];
	for (int i = 2; i < p; i++) {
		if (curspeed < real[i]) group--;
		else curspeed = min(curspeed, real[i]);
	}
	printf("%d\n", group);
	return 0;
}