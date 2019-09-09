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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,1,-1,1,-1 };
int a, b,ans;
void go(ll sum,int cnt, int depth) {
	if (cnt > depth) {
		return;
	}
	if (sum >= a && sum <= b) ans++;
	go(sum * 10 + 4, cnt + 1, depth);
	go(sum * 10 + 7, cnt + 1, depth);
}
int main() {
	scanf("%d%d", &a,&b);
	string s = to_string(b);
	go(0,0,s.size());
	printf("%d\n", ans);
	return 0;
}