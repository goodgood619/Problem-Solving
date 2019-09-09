#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
ll height[55];
int cnt[55];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%lld", &height[i]);}
	double Max = -1e10;
	for (int i = 1; i <= n; i++){
		Max = -1e10;
		for (int j = i + 1; j <= n; j++) {
			double d = (double)(height[j] - height[i]) / (j - i);
			if (Max < d) {
				Max = d;
				cnt[i]++;
				cnt[j]++;
			}
		}
	}
	int MAX = 0;
	for (int i = 1; i <= 50; i++) {
		MAX= max(MAX, cnt[i]);
	}
	printf("%d\n", MAX);
	return 0;
}

