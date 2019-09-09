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
#define mod 1000000009
#define lim 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t;
bool check[10005];
vector<int> v;
int bfs(int st, int en) {
	bool visited[10005] = { false, };
	visited[st] = true;
	queue<P> q;
	q.push({ st,0 });
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == en) return cnt;
		string s = to_string(num);
		for (int i = 0; i <s.size(); i++) {
			char c = s[i];
			for (int j = 0; j < 10; j++) {
				if (c == j + '0') continue;
				s[i] = j+'0';
				int newnum = stoi(s);
				vector<int>::iterator it = lower_bound(v.begin(), v.end(), newnum);
				if (it == v.end()) continue;
				if (*it == newnum && !visited[newnum] && newnum>=1000 && newnum<10000) {
					q.push({ newnum,cnt + 1 });
					visited[newnum] = true;
				}
			}
			s[i] = c;
		}
	}
	return -1;
}
int main(void) {
	for (int i = 2; i <= sqrt(10000); i++) {
		if (check[i]) continue;
		for (int j = i * i; j <= 10000; j += i) {
			check[j] = true;
		}
	}
	for (int i = 2; i < 10000; i++) {
		if (!check[i]) v.push_back(i);
	}
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int ans=bfs(n, m);
		ans == -1 ? printf("Impossible") : printf("%d\n", ans);
	}
	return 0;
}