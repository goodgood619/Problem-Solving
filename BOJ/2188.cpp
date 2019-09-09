#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct Edge{
	int flow, to, capacity;
	Edge *reverse;
	Edge(int to1, int c1) :to(to1), flow(0), capacity(c1), reverse(nullptr){}
	int spare() {
		return capacity - flow;
	}
	void addflow(int Flow) {
		flow += Flow;
		reverse->flow -= Flow;
	}
};
vector <Edge*> a[450];
int pre[450];
int n, m;
#define INF 99999999
int main(){
	scanf("%d%d", &n, &m);
	int source = 401;
	int sink = 402;
	vector<int> sinksink;
	for (int i = 1; i <= n; i++) {
		Edge *e1 = new Edge(i, 1);
		Edge *e2 = new Edge(source, 0);
		e1->reverse = e2;
		e2->reverse = e1;
		a[source].push_back(e1);
		a[i].push_back(e2);
		int work;
		scanf("%d", &work);
		for (int j = 1; j <= work; j++){
			int num;
			scanf("%d", &num);
			num += 200;
			sinksink.push_back(num);
			Edge *e1 = new Edge(num, 1);
			Edge *e2 = new Edge(i, 0);
			e1->reverse = e2;
			e2->reverse = e1;
			a[i].push_back(e1);
			a[num].push_back(e2);
		}
	}
	sort(sinksink.begin(), sinksink.end());
	sinksink.erase(unique(sinksink.begin(), sinksink.end()),sinksink.end());
	for (int i = 0; i < sinksink.size(); i++) {
		int num = sinksink[i];
		Edge *e1 = new Edge(sink, 1);
		Edge *e2 = new Edge(num, 0);
		e1->reverse = e2;
		e2->reverse = e1;
		a[num].push_back(e1);
		a[sink].push_back(e2);
	}
	int total = 0;
	while (1) {
		memset(pre, -1, sizeof(pre));
		Edge *path[450] = { 0 };
		queue <int> q;
		q.push(source);
		while (!q.empty() && pre[sink]==-1) {
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
		for (int i = sink; i != source; i = pre[i]) {
			path[i]->addflow(minflow);
		}
		total += minflow;
	}
	printf("%d\n", total);
	return 0;
}