#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int n, k, m;
typedef pair<int, int> P;
vector<P>se;
int h = 1;
bool visited[50005];
P position[50005];
#define INF 999999999
vector<vector<int>> a;
int cnt,ptr;
void update(int index, int value,int here) {
	index += h - 1;
	se[index] = { value,here };
	while (index > 1) {
		index /= 2;
		se[index] = min(se[2 * index], se[2 * index + 1]);
	}
}
P query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) return se[nodeNum];
	else if (L > nodeR || R < nodeL) return { INF,INF };
	int mid = (nodeL + nodeR) / 2;
	return min(query(L, R, nodeNum * 2, nodeL, mid), query(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}
void dfs(int here, int depth) {
	if (visited[here]) return;
	visited[here] = true;
	cnt++;
	update(cnt, depth, here);
	position[here].first=cnt;
	for (int i = 0; i < a[here].size(); i++){
		int next = a[here][i];
		if (!visited[next]){
			dfs(next, depth + 1);
			cnt++;
			position[here].second=cnt;
			update(cnt, depth, here);
		}
	}
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	while (h < 2 * n) h *= 2;
	se.resize(h * 2);
	for (int i = 1; i <=n-1; i++){
		int first, second;
		scanf("%d%d", &first,&second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	for (int i = 1; i < se.size(); i++) {
		se[i].first = INF;
		se[i].second = INF;
	}
	dfs(1, 0);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		int left = min(position[first].first, position[second].first);
		int right = max(position[first].first, position[second].first);
		if (left > right) {
			int temp = left;
			left = right;
			right = temp;
		}
		int minindex=query(left, right, 1, 1, h).second;
		printf("%d\n", minindex);
	}
	return 0;
}