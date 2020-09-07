#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
struct pp {
    int next, cost;
};
struct ppp {
    int here, cost;
};
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
bool compare(const pp &a, const pp &b) {
    if (a.cost != b.cost) return a.cost < b.cost;
    if (a.next != b.next) return a.next < b.next;
}
int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    queue<ppp> q;
    vector<bool> visited;
    vector<vector<pp>> graph;
    visited.assign(N + 1, false);
    graph.assign(N+1,vector<pp>());
    for (int i = 0; i < road.size(); ++i) {
        int here = road[i][0], next = road[i][1], cost = road[i][2];
        graph[here].push_back({ next,cost });
        graph[next].push_back({ here,cost });
    }
    for (int i = 0; i < graph.size(); i++) {
        sort(graph[i].begin(), graph[i].end(), compare);
    }
    q.push({ 1,0 });
    visited[1] = true;
    vector<int> ans;
    ans.assign(N + 1,0);
    while (!q.empty()) {
        int here = q.front().here;
        int cost = q.front().cost;
        q.pop();
        for (auto next : graph[here]) {
            if (!visited[next.next]) {
                visited[next.next] = true;
                q.push({ next.next,next.cost + cost });
                ans[next.next] = next.cost + cost;
            }
            else {
                if (ans[next.next] > next.cost + cost) {
                    ans[next.next] = next.cost + cost;
                    q.push({ next.next,next.cost + cost });
                }
            }
        }
    }

    for (int i = 1; i < ans.size();i++) {
        if (ans[i] <= K) answer++;
    }
    return answer;
}