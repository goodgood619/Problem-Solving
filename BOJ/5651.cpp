#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
	int flow, to, capacity;
	Edge* reverse;
	Edge(int to1, int c1) :to(to1), flow(0), capacity(c1), reverse(nullptr) {}
	int spare() {
		return capacity - flow;
	}
	void addflow(int Flow) {
		flow += Flow;
		reverse->flow -= Flow;
	}
};
int t,n, m;
int pre[350];
#define INF 999999999
int main(){
	scanf("%d", &t);
	while (t--){
		vector<Edge*> a[350];
		a->clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int first, second, cap;
			scanf("%d%d%d", &first, &second, &cap);
			Edge *e1 = new Edge(second, cap);
			Edge *e2 = new Edge(first, 0);
			e1->reverse = e2;
			e2->reverse = e1;
			a[first].push_back(e1);
			a[second].push_back(e2);
		}
		int source = 1;
		int sink = n;
		int total = 0;
		int totalcnt = 0;
		while (1) {
			memset(pre, -1, sizeof(pre));
			Edge *path[350] = {0};
			queue <int> q;
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
			for (int i = sink; i != source; i = pre[i]) {
				minflow = min(minflow, path[i]->spare());
			}
			for (int i = sink; i != source; i = pre[i])
				path[i]->addflow(minflow);
			total += minflow;
		}
		// 여기서 포화간선을 기준으로 용량을 1줄이고, 다른 정점으로 뿌려보자
		for (int i = 1; i <= n; i++) {
			if (a[i].size() == 0) continue;
			else {
				for (Edge *e : a[i]){
					memset(pre, -1, sizeof(pre));
					Edge *path[350] = { 0 };
					int sink = e->to;
					int sp = e->spare();
					int cap = e->capacity;
					if (sp != 0 || cap==0) continue;
					queue<int> q;
					q.push(i);
					while (!q.empty()){
						int here = q.front();
						q.pop();
						for (Edge *e : a[here]) {
							int next = e->to;
							if (pre[next] == -1 && e->spare() > 0) {
								pre[next] = here;
								path[next] = e;
								q.push(next);
							}
						}
					}
					if (pre[sink] == -1) totalcnt++;
				}
			}
		}
		printf("%d\n", totalcnt);
	}
	return 0;
}