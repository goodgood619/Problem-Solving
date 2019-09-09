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
int n;
int dist[250005];
int path[250005];
bool visited[250005];
vector<vector<PPP>> temp;
vector<vector<int>> a;
void bfs(int here) {
	queue<int> q;
	q.push(here);
	dist[here] = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				dist[next] = dist[here] + 1;
				path[next] = here;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	vector<PPP> v;
	a.resize(n*n-n/2+1);
	temp.resize(n + 1);
	for (int i = 1; i <= n * n - n / 2; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back({ i,{x,y} });
	}
	int here = 1;
	int ptr = 0;
	while (here < n+1) {
		for (int i = 1; i <= n; i++) {
			temp[here].push_back(v[ptr++]);
		}
		here++;
		if (here == n+1) break;
		for (int i = 1; i <= n - 1; i++) {
			temp[here].push_back(v[ptr++]);
		}
		here++;
	}

	for (int i = 2; i < temp.size(); i += 2) {

		for (int j = 0; j < temp[i].size(); j++) {
			//왼쪽에서 일, 오른쪽에서 일을 하면 된다
			PPP here = temp[i][j];
			int up = i - 1;
			int down = i + 1;
			int nleft = j - 1;
			int nright = j + 1;
			if (up >= 1) {
				PPP next = temp[up][j];
				if (here.second.first == next.second.second) { //연결
					a[here.first].push_back(next.first);
					a[next.first].push_back(here.first);
				}
			}
			if (down <=n) {
				PPP next = temp[down][j];
				if (here.second.first == next.second.second) {
					a[here.first].push_back(next.first);
					a[next.first].push_back(here.first);
				}
			}
			if (nleft >= 0) {
				PPP next = temp[i][nleft];
				if (here.second.first == next.second.second) {
					a[here.first].push_back(next.first);
				}
			}
			if (up >= 1) {
				PPP next = temp[up][j+1];
				if (here.second.second == next.second.first) { //연결
					a[here.first].push_back(next.first);
					a[next.first].push_back(here.first);
				}
			}
			if (down <=n) {
				PPP next = temp[down][j+1];
				if (here.second.second == next.second.first) {
					a[here.first].push_back(next.first);
					a[next.first].push_back(here.first);
				}
			}
			if (nright<temp[i].size()) {
				PPP next = temp[i][nright];
				if (here.second.second == next.second.first) {
					a[here.first].push_back(next.first);
				}
			}
		}
	}
	//홀수양옆에는 따로 연결
	for (int i = 1; i < temp.size(); i += 2) {
		for (int j = 0; j < temp[i].size(); j++) {
			PPP here = temp[i][j];
			int nleft = j - 1;
			int nright = j + 1;
			if (nleft >= 0) {
				PPP next = temp[i][nleft];
				if (here.second.first == next.second.second) {
					a[here.first].push_back(next.first);
				}
			}
			if (nright < temp[i].size()) {
				PPP next = temp[i][nright];
				if (here.second.second == next.second.first) {
					a[here.first].push_back(next.first);
				}
			}
		}
	}
	bfs(1);
	if (dist[n*n - n / 2] != 0) { //끝점에 도달했을경우
		printf("%d\n", dist[n*n - n / 2]);
		int p = n * n - n / 2;
		vector<int> v;
		while (p != 1) {
			v.push_back(p);
			p = path[p];
		}
		v.push_back(1);
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
	}
	else {
		int en = 0;
		for (int i = n * n - n / 2; i >= 1; i--) {
			if (dist[i] != 0) {
				en = i;
				break;
			}
		}
		printf("%d\n", dist[en]);
		vector<int> v;
		while (en!= 1) {
			v.push_back(en);
			en = path[en];
		}
		v.push_back(1);
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
	}
	return 0;
}