#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
bool visited[100005];
int n,st,en;
typedef pair<int, int> P;
int ans = 999999999;
vector<vector<P>> a;
vector<int> pos;
vector<int> route;
// DFS 한번돌려서 최소길이를 찾고, 그 최소길이를 추적한다음에, 그중에서 Max길이를 빼면됨 ㅇㅇ
void dfs(int here,int sum){
	if (visited[here]) return;
	if (here == en){
		if (ans > sum) {
			ans = min(ans, sum);
			for (int i = 0; i < pos.size(); i++) {
				route.push_back(pos[i]);
			}
		}
	}
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i].first;
		int cost = a[here][i].second;
		if (!visited[next]){
			pos.push_back(next);
			dfs(next, sum+cost);
			pos.pop_back();
		}
	}
}
int main(){
	scanf("%d%d%d", &n,&st,&en);
	a.resize(n + 1);
	for (int i = 1; i <= n-1; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	pos.push_back(st);
	dfs(st,0);

	int here = st;
	int Max = 0;
	for (int i = 0; i < route.size(); i++) {
		int next = route[i];
		for (int j = 0; j<a[here].size(); j++) {
			int check = a[here][j].first;
			if (next == check){
				Max = max(Max, a[here][j].second);
				break;
			}
			else continue;
		}
		here = next;
	}
	printf("%d\n", ans - Max);
	return 0;
}