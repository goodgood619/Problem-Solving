#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n;
#define INF 999999999
int pre[55];
struct Edge {
	int target, capacity, flow;
	Edge* reverse;
	Edge(int to1, int c1) :target(to1), capacity(c1), flow(0), reverse(nullptr){
	}
	int spare(){
		return capacity - flow;
	}
	void goflow(int Flow) {
		flow += Flow;
		reverse->flow -=Flow;
	}
};
int gogo(char c) {
	if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
	else return c - 'Z' + 20;
}
vector<Edge*> a[55];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char first, second;
		int water;
		scanf(" %c %c %d", &first, &second, &water);
		int one = gogo(first);
		int two = gogo(second);
		Edge *newedge1 = new Edge(two,water);
		Edge *newedge2 = new Edge(one, water);
		newedge1->reverse = newedge2;
		newedge2->reverse = newedge1;
		a[one].push_back(newedge1);
		a[two].push_back(newedge2);
	}
	int total = 0;
	int source = 1;
	int sink = 26;

	while (1) {
		memset(pre, -1, sizeof(pre));
		Edge* path[55] = { 0, };
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int here = q.front();
			if (here == sink) break;
			q.pop();
			for (Edge*e : a[here]){
				int next=e->target;
				if (e->spare() > 0 && pre[next] == -1){
					q.push(next);
					pre[next] = here;
					path[next] = e;
				}
			}
		}
		if (pre[sink]== -1) break;
		int minflow = INF;
		for (int i = sink; i != source; i = pre[i]) {
			minflow = min(minflow, path[i]->spare());
		}
		for (int i = sink; i != source; i = pre[i]){
			path[i]->goflow(minflow);
		}
		total += minflow;
	}
	printf("%d\n", total);

	return 0;
}