#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <functional>
using namespace std;
struct p {
    int x, y;
};
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
typedef pair<int, pair<int, int>> P;
vector<vector<bool>> visited;
vector<vector<int>> areas;
vector<vector<int>> numbering;
void bfs(int x, int y, int height, int area,vector<vector<int>> &land) {
    queue<p> q;
    q.push({ x,y });
    visited[x][y] = true;
    int n = land.size();
    numbering[x][y] = area;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny<0 || ny >= n || abs(land[x][y] - land[nx][ny])>height || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            numbering[nx][ny] = area;
            q.push({ nx,ny });
        }
    }
}
int find(int u, vector<int>& parent) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u], parent);
}
void merge(int u, int v, vector<int>& parent) {
    u = find(u, parent), v = find(v, parent);
    if (u == v) return;
    parent[u] = v;
}
int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int n = land.size();
    numbering.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<bool>(n, false));
    int area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) {
                bfs(i, j,height,area,land);
                area++;
            }
        }
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + gox[k], ny = j + goy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || numbering[i][j] == numbering[nx][ny]) continue;
                pq.push({ abs(land[i][j] - land[nx][ny]),{numbering[i][j],numbering[nx][ny]}});
            }
        }
    }
    vector<int> parent;
    parent.assign(pq.size(), 0);
    for (int i = 0; i < parent.size(); ++i) parent[i] = i;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (find(x, parent) != find(y, parent)) {
            merge(x, y, parent);
            answer += cost;
        }
    }
    return answer;
}