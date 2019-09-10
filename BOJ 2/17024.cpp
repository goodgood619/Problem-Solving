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
#define mod 1000000007
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
int cnt[100001];
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &n);
	for (int i = 1; i <= n-1; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		cnt[first]++, cnt[second]++;
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		Max = max(Max, cnt[i]);
	}
	printf("%d\n", Max + 1);
	return 0;
}