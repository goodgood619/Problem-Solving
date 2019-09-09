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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, n, k;
vector<ll> maxseg, minseg;
int DVD[100005];
int h = 1;
void maxupdate(int index, ll value) {
	index += h - 1;
	maxseg[index] = value;
	while (index > 1) {
		index /= 2;
		maxseg[index] =max(maxseg[index * 2] , maxseg[index * 2 + 1]);
	}
}
void minupdate(int index,ll value) {
	index += h - 1;
	minseg[index] = value;
	while (index > 1) {
		index /= 2;
		minseg[index] = min(minseg[index * 2] ,minseg[index * 2 + 1]);
	}
}
ll maxquery(int nodenum, int left, int right, int nodeleft, int noderight) {
	if (noderight < left || right < nodeleft) return -1;
	else if (left <= nodeleft && noderight <= right) return maxseg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return max(maxquery(nodenum * 2, left, right, nodeleft, mid),maxquery(nodenum * 2 + 1, left, right, mid + 1, noderight));
}
ll minquery(int nodenum, int left, int right, int nodeleft, int noderight) {
	if (noderight < left || right < nodeleft) return 1e9;
	else if (left <= nodeleft && noderight <= right) return minseg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return min(minquery(nodenum * 2, left, right, nodeleft, mid),minquery(nodenum * 2 + 1, left, right, mid + 1, noderight));
}
int main() {
	scanf("%d", &t);
	while (t--) {
		h = 1;
		minseg.clear(), maxseg.clear();
		memset(DVD, 0, sizeof(DVD));
		scanf("%d%d", &n, &k);
		while (h < n) h <<= 1;
		maxseg.resize(h * 2), minseg.resize(h * 2, 1e9);
		for (int i = 1; i <= n; i++) {
			minupdate(i, i-1);
			maxupdate(i, i - 1);
			DVD[i] = i - 1;
		}
		for (int i = 1; i <= k; i++) {
			int what;
			scanf("%d", &what);
			if (what == 1) { //값이 올바른지 비교
				ll left, right;
				scanf("%lld%lld", &left, &right);
				ll c = minquery(1, left+1, right+1, 1, h);
				ll r = maxquery(1, left+1, right+1, 1, h);
				c == left && r==right ? printf("YES\n") : printf("NO\n");
			}
			else { //바꿔야될 위치 찾고 그값을 업데이트
				ll left, right;
				scanf("%lld%lld", &left, &right);
				left += 1, right += 1;
				swap(DVD[left], DVD[right]);
				minupdate(left, DVD[left]);
				maxupdate(left, DVD[left]);
				minupdate(right,DVD[right]);
				maxupdate(right,DVD[right]);
			}
		}
	}
	return 0;
}