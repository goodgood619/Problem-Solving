
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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
vector<pair<int, int>> v;
int dist(pair<int,int> a,pair<int,int> b) {
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
bool compare(const pair<int,int> &a,const pair<int,int> &b) {
	if (a.second != b.second) return a.second < b.second;
	if (a.first != b.first) return a.first < b.first;
}
int closest(int left,int right) {
	int rest = right - left + 1;
	if (rest == 1) return 1e9;
	if (rest == 2) return dist(v[0], v[1]);
	if (rest == 3) {
		return min({ dist(v[0],v[1]),dist(v[0],v[2]),dist(v[1],v[2]) });
	}
	int ret = 1e9;
	int mid = (left + right) / 2;
	ret = min(closest(left, mid - 1), closest(mid+1, right));
	vector<pair<int,int>> Mid;
	for (int i = mid - 1; i >= left; i--) {
		int d = dist({v[mid].first,0}, {v[i].first,0 });
		if (d >= ret) break;
		else Mid.push_back(v[i]);
	}

	for (int i = mid + 1; i <= right; i++) {
		int d = dist({v[mid].first,0}, {v[i].first,0 });
		if (d >= ret) break;
		else Mid.push_back(v[i]);
	}
	Mid.push_back(v[mid]);
	sort(Mid.begin(), Mid.end(), compare);
	int no = 0;
	for (int i = 0; i < Mid.size() - 1; i++) {
		for (int j = i + 1; j < Mid.size(); j++) {
			int d = dist({ Mid[i].second,0 }, {Mid[j].second,0});
			if (d >= ret) {
				break;
			}
			else ret = min(ret, dist(Mid[i],Mid[j]));
		}
	}
	return ret;
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	printf("%d\n", closest(0, n - 1));
	return 0;
}
