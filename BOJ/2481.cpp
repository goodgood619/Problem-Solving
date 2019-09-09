#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <cstring>
using namespace std;
typedef long long ll;
map<int,int> m;
typedef pair<pair<int, int>,int> P;
vector<vector<int>> a;
queue <int> q;
vector<P> anspo;
int n, k, j,en;
bool visited[100004];
vector<int> ans;
vector<int> real;
char key[35];
bool check;
void go(int en){
	if (ans[en] == 0) return;
	else{
		go(ans[en]);
		real.push_back(ans[en]);
	}
}
void bfs(int here,int cnt){
	q.push(here);
	while (!q.empty()){
		int here = q.front();
		q.pop();
		if (here == en){
			check = true;
		}
		for (int i = 0; i < a[here].size(); i++){
			int next = a[here][i];
			if (!visited[next]){
				visited[next] = true;
				q.push(next);
				ans[next] = here;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	a.resize(n+ 1);
	ans.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%s", key);
		int length = strlen(key);
		int sum = 0;
		for (int i = length - 1; i >= 0; i--) {
			int value = key[i] - '0';
			sum += value*pow(2, length - i - 1);
		}
		m.insert({ sum,i });
		anspo.push_back({ { sum,i }, length });
	}
	for (int i = 0; i <n; i++) {
		int value = anspo[i].first.first;
		int index = anspo[i].first.second;
		int length = anspo[i].second;
		int p = 0;
		int V = value;
		int XOR = 1;
		while (p != length) {
			V ^= XOR;
			if (m.count(V) != 0)
			{
				int Index = m[V];
				a[index].push_back(Index);
			}
			XOR *= 2;
			p++;
			V = value;
		}
	}
	int start = anspo[0].first.second;
	scanf("%d", &j);
	for (int i = 1; i <= j; i++){
		real.clear();
		check = false;
		memset(visited, false, sizeof(visited));
		scanf("%d", &en);
		visited[start] = true;
		bfs(start,0);
		if (!check) printf("-1");
		else{
			go(en);
			real.push_back(en);
			for (int i = 0; i < real.size(); i++){
				printf("%d ", real[i]);
			}
		}
		printf("\n");
		ans.clear();
	}
	return 0;
}