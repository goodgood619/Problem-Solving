#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef int64_t ll;
typedef pair<int, pair<int, int>> p;
int find(int u, int*& parent) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u],parent);
}
void uni(int u, int v, int*& parent) {
    u = find(u, parent), v = find(v, parent);
    if (u == v) return;
    parent[u] = v;
}
int main() {
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    priority_queue<p, vector<p>, greater<p>> pq;
    int* parent = new int[n + 1];
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        int here, next, cost;
        scanf("%d%d%d", &here, &next, &cost);
        pq.push({ cost,{here,next}});
    }
    int ans = 0,cnt=0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second.first;
        int next = pq.top().second.second;
        pq.pop();
        if (find(here, parent) != find(next, parent)) {
            uni(here, next, parent);
            ans = ans + cost + cnt * t;
            cnt++;
        }
    }
    printf("%d\n", ans);
    delete[] parent;
    return 0;
}