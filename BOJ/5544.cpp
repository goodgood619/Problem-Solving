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
typedef pair<pair<int, int>,string> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int rx[8] = { 0,0,1,-1,1,1,-1,-1 };
int ry[8] = { 1,-1,0,0,1,-1,1,-1 };
int n;
int score[105];
int ans[105];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n * (n - 1) / 2; i++) {
		int first, second, fscore, sscore;
		scanf("%d%d%d%d", &first, &second, &fscore, &sscore);
		if (fscore > sscore) {
			score[first] += 3;
		}
		else if (fscore == sscore) {
			score[first] += 1;
			score[second] += 1;
		}
		else {
			score[second] += 3;
		}
	}
	vector<P> v;
	for (int i = 1; i <= n; i++) {
		v.push_back({ score[i],i });
	}
	sort(v.begin(), v.end(),greater<>());
	map<int, int> m;
	for (int i = 0; i < v.size(); i++) {
		m[v[i].first]++;
	}
	for (int i = 0; i < v.size(); i++) {
		int score = v[i].first;
		int teamnum = v[i].second;
		map<int, int>::reverse_iterator it;
		int cnt = 1;
		for(it=m.rbegin();it != m.rend();it++){
			if (score == it->first) {
				ans[teamnum] = cnt;
				break;
			}
			else cnt += it->second;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}