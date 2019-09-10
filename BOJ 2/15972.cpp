#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
typedef pair<int, int> P;
int n, m, h;
vector<vector<P>> a;
typedef pair<int, pair<int, int>> PP;
// 2000*2000으로 늘려서
// 맨 바깥쪽라인을 싹훝은다음에 우선순위큐를 쓰면 높이가 최소값부터 정렬이 알아서 될터이니 ㅇㅇ..에다가...
int board[2005][2005];
int ans[1000300];
bool visited[2005][2005];
priority_queue <P, vector<P>, greater<P>> pq;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int main() {
	scanf("%d%d%d", &n, &m, &h);
	a.resize((n + 2)*(m + 2));
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			board[i][j] = cnt;
			cnt++;
		}
	}
	for (int i = 1; i <= n+1; i++) {
		for (int j = 1; j <=m; j++) {
			int hole;
			scanf("%d", &hole);
			if (hole == -1) continue;
			else {
				a[board[i][j]].push_back({ board[i - 1][j],hole });
				a[board[i - 1][j]].push_back({ board[i][j],hole });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=m+1; j++) {
			int hole;
			scanf("%d", &hole);
			if (hole == -1) continue;
			else{
				a[board[i][j]].push_back({ board[i][j - 1],hole });
				a[board[i][j-1]].push_back({ board[i][j],hole });
			}
		}
	}

	for (int i = 1; i <= n*m; i++)ans[i] = h;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int height = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextheight = a[here][i].second;
			if (ans[next] > max(nextheight, height)) { // 최소의 최대가 되게 하는게 목적인듯
				ans[next] = max(nextheight, height);
				pq.push({ ans[next],next });
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n*m; i++) { sum += ans[i]; }
	printf("%d\n", sum);
	return 0;
}