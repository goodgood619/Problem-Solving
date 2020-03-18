#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
using namespace std;
typedef int64_t ll;
int go(int here, int parent,vector<vector<int>> &graph,bool* &visited,bool* &cycle) {
    if (visited[here]) {
        return here;
    }
    visited[here] = true;
    for (auto next : graph[here]) {
        if (next == parent) continue;
        int ret = go(next, here, graph, visited, cycle);
        if (ret == 1e9) return 1e9;
        if (ret > 0) {
            cycle[here] = true;
            if (here == ret) return 1e9;
            else return ret;
        }
    }
    return -1;
}
int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> graph;
    graph.assign(n + 1, vector<int>());
    bool* visited = new bool[n + 1];
    bool* cycle = new bool[n + 1];
    int* dist = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        dist[i] = 0;
        visited[i] = false;
        cycle[i] = false;
    }
    for (int i = 0; i < n; i++) {
        int here, next;
        scanf("%d%d", &here, &next);
        graph[here].push_back(next);
        graph[next].push_back(here);
    }
    go(1, -1, graph, visited, cycle);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
   }
    for (int i = 1; i <= n; i++) {
        if (cycle[i]) {
            visited[i] = true;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (auto next : graph[here]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                dist[next] = dist[here] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
    delete[] visited, cycle, dist;
    return 0;
}