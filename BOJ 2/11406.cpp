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
vector<Edge*> a[300];
int pre[300];
#define INF 99999999
int main(){
	scanf("%d%d", &n, &m);
	int source = 0;
	int sink = 250;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		Edge *e1 = new Edge(i, num);
		Edge *e2 = new Edge(source, 0);
		e1->reverse = e2;
		e2->reverse = e1;
		a[source].push_back(e1);
		a[i].push_back(e2);
	}
	for (int i = 1; i <= m; i++) {
		int num;
		scanf("%d", &num);
		int book = i + 100;
		Edge *e1 = new Edge(sink, num);
		Edge *e2 = new Edge(book, 0);
		e1->reverse = e2;
		e2->reverse = e1;
		a[book].push_back(e1);
		a[sink].push_back(e2);
	}
	for (int j = 1; j <= m; j++){
		int book = j + 100;
		for (int i = 1; i<= n; i++) {
			int num;
			scanf("%d", &num);
			if (num == 0) continue;
			Edge *e1 = new Edge(book, num);
			Edge *e2 = new Edge(i, 0);
			e1->reverse = e2;
			e2->reverse = e1;
			a[i].push_back(e1);
			a[book].push_back(e2);
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