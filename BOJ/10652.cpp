#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
ll dist[40005];
ll dist2[40005];
ll dist3[40005];
bool visited[40005];
int b, e, p, n, m;
vector<vector<ll>> a;
queue<ll> q;
void bfs(int here,int what){
	q.push(here);
	visited[here] = true;
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int next = a[x][i];
			if (!visited[next]) {
				visited[next] = true;
				if (what == 1)
					dist[next] = dist[x] + 1;
				else if (what == 2)
					dist2[next] = dist2[x] + 1;
				else if (what == 3)
					dist3[next] = dist3[x] + 1;
				q.push(next);
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d", &b, &e, &p, &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	bfs(1,1);
	memset(visited, false, sizeof(visited));
	bfs(2,2);
	memset(visited, false, sizeof(visited));
	bfs(n,3);
	ll Min = 100000000000000;

	for (int i = 1; i <= n; i++){
		Min = min(Min, dist[i]*b+dist2[i]*e+dist3[i]*p);
	}
	printf("%lld\n", Min);
	return 0;
}