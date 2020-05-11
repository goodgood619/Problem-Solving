#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef int64_t ll;
struct p {
    int place, time, money;
};
typedef pair<int, pair<int, int>> PP;
int dijk(vector<vector<p>>& graph, int t, int m, int n) {
    priority_queue<PP, vector<PP>, greater<PP>> pq;
    pq.push({ 0,{t,1} });
    vector<vector<int>> dist;
    dist.assign(n + 1, vector<int>(t + 1, 1e9));
    dist[1][t] = 0;
    int ans = 1e9;
    while (!pq.empty()) {
        int curmoney = pq.top().first;
        int time = pq.top().second.first;
        int here = pq.top().second.second;
        pq.pop();
        if (dist[here][time] < curmoney) continue;
        if (here == n) {
            if (curmoney <= m) {
                ans = curmoney;
                break;
            }
        }
        for (auto ele : graph[here]) {
            int next = ele.place;
            int nexttime = ele.time;
            int money = ele.money;
            if (time >= nexttime && dist[next][time - nexttime] > dist[here][time] + money) {
                dist[next][time - nexttime] = dist[here][time] + money;
                pq.push({ dist[next][time-nexttime], {time - nexttime,next}});
            }
        }
    }
    dist.clear();
    if (ans == 1e9) return -1;
    return ans;
}
int main()
{
    int n, t, m, l;
    scanf("%d", &n);
    scanf("%d%d", &t, &m);
    scanf("%d", &l);
    vector<vector<p>> graph;
    graph.assign(n + 1, vector<p>());
    for (int i = 0; i < l; i++) {
        int start, end, time, money;
        scanf("%d%d%d%d", &start, &end, &time, &money);
        graph[start].push_back({ end,time,money });
        graph[end].push_back({ start,time,money });
    }
    printf("%d\n",dijk(graph, t, m, n));
    graph.clear();
    return 0;
}