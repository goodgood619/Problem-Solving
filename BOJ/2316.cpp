#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n, ans;
#define INF 999999999
struct Edge {
	int to, flow, capacity;
	Edge* reverse;
	Edge() :Edge(-1, 0) {}
	Edge(int to1, int c1) :to(to1), flow(0), capacity(c1), reverse(nullptr) {}
	int spare() {
		return capacity - flow;
	}
	void goflow(int Flow) {
		flow += Flow;
		reverse->flow -= Flow;
	}
};
vector<Edge*> a[820];
int pre[820];
int main() {
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++) {
		int in = i;
		int out = i + n;
		Edge* e1 = new Edge(out, 1);
		Edge* e2 = new Edge(in, 0); // 이게 용량을 0으로 주는게 역방향 간선의 의미인데 이게헷갈리네(절대흐를수없다면 0이맞네)
		e1->reverse = e2;
		e2->reverse = e1;
		a[in].push_back(e1);
		a[out].push_back(e2);
	}
	for (int i = 1; i <= p; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		int firstout = first + n;
		int secondout = second + n;
		Edge *e1 = new Edge(second, 1);
		Edge *e2 = new Edge(firstout, 0);
		Edge *e3 = new Edge(first, 1);
		Edge *e4 = new Edge(secondout, 0);
		e1->reverse = e2;
		e2->reverse = e1;
		e3->reverse = e4;
		e4->reverse = e3;
		a[firstout].push_back(e1);
		a[second].push_back(e2);
		a[secondout].push_back(e3);
		a[first].push_back(e4);
	}
	int source = 1 + n;
	int sink = 2;
	int total = 0;
	while (1) {
		memset(pre, -1, sizeof(pre));
		Edge *path[820] = { 0 };
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
					if (next == sink) break;
				}
			}
		}
		if (pre[sink] == -1) break;
		int minflow = INF;
		for (int i = sink; i != source; i = pre[i]) {
			minflow = min(minflow, path[i]->spare());
		}
		for (int i = sink; i != source; i = pre[i]) {
			path[i]->goflow(minflow);
		}
		total += minflow;
	}
	printf("%d\n", total);
	return 0;
}