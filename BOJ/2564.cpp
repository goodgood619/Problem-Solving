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
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
int x, y,tx,ty;
int n;
int go(int tx,int ty,int tg,int sx,int sy,int sg) {
	if (tg == sg) {
		if (tg == 1 || tg == 2) {
			return abs(ty - sy);
		}
		else {
			return abs(tx - sx);
		}
	}
	else {
		if (tg + sg == 3 || tg+sg==7) { //반대쪽에 있거나
			if (tg + sg == 3) {
				int temp1 = abs(x + ty + sy),temp2=abs(x+y-ty+y-sy);
				return min(temp1, temp2);
			}
			else {
				int temp1 = abs(y + tx + sx), temp2 = abs(y + x - tx + x - sx);
				return min(temp1, temp2);
			}
		}
		else { // 모서리쪽
			return abs(tx - sx) + abs(ty - sy);
		}
	}
}
int main() {
	scanf("%d%d", &y, &x);
	scanf("%d", &n);
	vector<PP> v;
	for (int i = 1; i <= n + 1; i++) {
		int dir, z, sx = -1, sy = -1;
		scanf("%d%d", &dir, &z);
		if (dir == 1) {
			sx = 0, sy = z;
		}
		else if (dir == 2) {
			sx = x, sy = z;
		}
		else if (dir == 3) {
			sx = z, sy = 0;
		}
		else if (dir == 4) {
			sx = z, sy = y;
		}
		v.push_back({{ sx,sy }, dir});
	}
	int ans = 0;
	for (int i = 0; i < v.size()-1; i++) {
		int sum = go(v[v.size() - 1].first.first, v[v.size() - 1].first.second,v[v.size()-1].second, v[i].first.first, v[i].first.second,v[i].second);
		ans += sum;
	}
	printf("%d\n", ans);
	return 0;
}