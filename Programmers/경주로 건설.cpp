#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
struct p {
    int x, y, cost, dir;
};
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
// 0 : 동,1: 남, 2: 북, 3:서
int bfs(vector<vector<int>>& board) {
    int n = board.size();
    int answer = 1e9;
    queue<p> q;
    vector<vector<bool>> visited;
    visited.assign(n, vector<bool>(n, false));
    vector<vector<int>> dist;
    dist.assign(n, vector<int>(n, 0));
    q.push({ 0,0,0,0 });
    q.push({ 0,0,0,1 });
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        int dir = q.front().dir;
        q.pop();
        if (x == n - 1 && y == n - 1) {
            answer = min(answer, cost);
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1) continue;
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                if (i != dir) {
                    q.push({ nx,ny,cost + 600,i });
                    dist[nx][ny] = cost + 600;
                }
                else {
                    q.push({ nx,ny,cost + 100,i });
                    dist[nx][ny] = cost + 100;
                }
            }
            else if (dist[nx][ny] >= cost + 600 && i != dir) {
                dist[nx][ny] = cost + 600;
                q.push({ nx,ny,cost + 600,i });
            }
            else if(dist[nx][ny]>=cost+100 && i==dir){
                dist[nx][ny] = cost + 100;
                q.push({ nx,ny,cost + 100,i });
            }
        }
    }
    return answer;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    answer = bfs(board);
    return answer;
}