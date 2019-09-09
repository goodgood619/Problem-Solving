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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int rx[8] = { 0,0,1,-1,1,1,-1,-1 };
int ry[8] = { 1,-1,0,0,1,-1,1,-1 };
int n, m, q;
int rog[105][17]; // 각각 팀이 몇번문제에 대해서 몇번틀렸는지
bool visited[105][17]; // 각각 팀이 해당 문제를 풀었는지
int total[105][17];
bool compare(const PP &a, const PP &b) {
	if (a.first.first != b.first.first) return a.first.first>b.first.first;
	if (a.first.second != b.first.second) return a.first.second<b.first.second;
	if (a.second != b.second) return a.second<b.second;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= q; i++) {
		int ti, tnum, pnum;
		string result;
		scanf("%d%d%d", &ti, &tnum, &pnum);
		cin >> result;
		if (result == "RE" || result=="TLE" || result=="WA") {
			if (visited[tnum][pnum]) continue;
			rog[tnum][pnum]++;
		}
		else {
			if (visited[tnum][pnum]) continue;
			visited[tnum][pnum] = true;
			total[tnum][pnum] = ti+rog[tnum][pnum] * 20;
		}
	}
	// 문제푼수,총시간,작은팀번호
	vector<PP> v;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		int ti = 0;
		for (int j = 1; j <= m; j++) {
			if (visited[i][j]) {
				ti += total[i][j];
				cnt++;
			}
		}
		v.push_back({ {cnt,ti },i });
	}
	sort(v.begin(),v.end(),compare);
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d %d\n", v[i].second, v[i].first.first, v[i].first.second);
	}
	return 0;
}