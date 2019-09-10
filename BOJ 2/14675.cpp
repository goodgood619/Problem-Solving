#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,m;
int indegree[100005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		indegree[first]++, indegree[second]++;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int t, k;
		scanf("%d%d", &t, &k);
		if (t == 1) indegree[k] == 1 ? printf("no\n") : printf("yes\n");
		else printf("yes\n");
	}
	return 0;
}