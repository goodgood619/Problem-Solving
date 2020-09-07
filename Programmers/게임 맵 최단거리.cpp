#include<vector>
#include <queue>
using namespace std;

struct p {
    int x, y, dist;
};
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int x = 0, y = 0;
    queue<p> q;
    q.push({ 0,0,1 });
    vector<vector<bool>> visited;
    visited.assign(n, vector<bool>(m, false));
    visited[0][0] = true;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            return dist;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || maps[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push({ nx,ny,dist + 1 });
        }
    }
    return -1;
}