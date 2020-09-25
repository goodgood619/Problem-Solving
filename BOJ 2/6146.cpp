#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int gox[4] = {-1,1,0,0};
int goy[4] = {0,0,-1,1};
struct p {
    int x, y, cost;
};
int bfs(int sx, int sy, int ex, int ey, vector<vector<int>>& board) {
    vector<vector<bool>> visited;
    visited.assign(1001, vector<bool>(1001, false));
    visited[sx][sy] = true;
    queue<p> q;
    q.push({ sx,sy,0 });
    int ans = 0;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        q.pop();
        if (x == ex && y == ey) {
            ans = cost;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx>1000 || ny < 0 || ny>1000 || visited[nx][ny] || board[nx][ny] == 1) continue;
            visited[nx][ny] = true;
            q.push({ nx,ny,cost + 1 });
        }
    }
    return ans;
}
int main()
{
    int sx, sy, k,ex=500,ey=500;
    vector<vector<int>> board;
    board.assign(1001, vector<int>(1001, 0));
    scanf("%d%d%d", &sx, &sy, &k);
    sx += 500, sy += 500;
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x += 500, y += 500;
        board[x][y] = 1;
    }
    printf("%d\n", bfs(sx, sy, ex, ey, board));
    return 0;
}