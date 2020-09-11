#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int ans;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
void dfs(int x,int y,int ex,int ey,vector<vector<bool>> &visited,vector<string> &board,int dist,int endDist,int n,int m) {
    if (x == ex && y == ey) {
        if (dist == endDist) ans++;
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + gox[i], ny = y + goy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'T' || visited[nx][ny]) continue;
        dfs(nx, ny, ex, ey, visited, board, dist + 1, endDist, n, m);
    }
    visited[x][y] = false;
}
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<string> board;
    for (int i = 0; i < n; i++) {
        string sin;
        cin >> sin;
        board.push_back(sin);
    }
    vector<vector<bool>> visited;
    visited.assign(n, vector<bool>(m, false));
    dfs(n - 1, 0, 0, m - 1, visited, board,1,k,n,m);
    printf("%d\n", ans);
    visited.clear();
    board.clear();
    return 0;
}