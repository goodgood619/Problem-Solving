#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int m, n;
struct Edge {
	int to, flow, capacity;
	Edge* reverse;
	Edge(int to1, int c1) :to(to1), flow(0), capacity(c1), reverse(nullptr) {}
	int spare() { return capacity - flow;}
	void addflow(int Flow) {
		flow += Flow;
		reverse->flow-=Flow;
	}
};
vector<Edge*> a[1500];
int pig[1005];
#define plus 1000
int pre[1500];
#define INF 99999999
int main(){
	scanf("%d%d", &m, &n);
	int source = 0;
	int sink = 1400;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &pig[i]);
		Edge *e1 = new Edge(sink,pig[i]);
		Edge *e2 = new Edge(i, 0);
		e1->reverse = e2;
		e2->reverse = e1;
		a[i].push_back(e1);
		a[sink].push_back(e2);
	}
	vector<vector<int>> share;
	share.resize(m+1);
	for (int i = 1; i <= n; i++) {
		int keycnt,person;
		scanf("%d", &keycnt);
		for (int j = 1; j <= keycnt; j++) {
			int from,who;
			scanf("%d", &from);
			who = plus + i;
			share[from].push_back(plus + i);
			Edge *e1 = new Edge(from,INF);
			Edge *e2 = new Edge(who, 0);
			e1->reverse = e2;
			e2->reverse = e1;
			a[who].push_back(e1);
			a[from].push_back(e2);
		}
		scanf("%d",&person);
		Edge *e1 = new Edge(plus+i, person);
		Edge *e2 = new Edge(source, 0);
		e1->reverse = e2;
		e2->reverse = e1;
		a[source].push_back(e1);
		a[plus+i].push_back(e2);
	}
	for (int i = 1; i <= m; i++) {
		if (share[i].size() == 0) continue;
		else {
			for (int j = 0; j < share[i].size()-1; j++) {
				int here = share[i][j];
				for (int k = j + 1; k < share[i].size(); k++) {
					int next = share[i][k];
					Edge *e1 = new Edge(next, 0);
					Edge *e2 = new Edge(here, INF);
					e1->reverse = e2;
					e2->reverse = e1;
					a[here].push_back(e1);
					a[next].push_back(e2);
				}
			}
		}
	}

	int total = 0;
	while (1) {
		memset(pre, -1, sizeof(pre));
		Edge* path[1500] = { 0 };
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (Edge *e : a[here]) {
				int next = e->to;
				if (e->spare() > 0 && pre[next] == -1) {
					pre[next] = here;
					path[next] = e;
					q.push(next);
				}
			}
		}
		if (pre[sink] == -1) break;
		int minflow = INF;
		for (int i = sink; i != source; i = pre[i])
			minflow = min(minflow, path[i]->spare());
		for (int i = sink; i != source; i = pre[i])
			path[i]->addflow(minflow);
		total += minflow;
	}
	printf("%d\n", total);
	return 0;
}