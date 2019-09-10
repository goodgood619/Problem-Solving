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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int, pair<ll, char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int num;
		scanf("%d", &num);
		if (num % 2 == 1) cnt += (num / 2) + 1;
		else cnt += (num / 2);
	}
	if (cnt >= n) printf("YES\n");
	else printf("NO\n");
	return 0;
}