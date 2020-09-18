#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int gox[4] = {-1,1,0,0};
int goy[4] = {0,0,-1,1};
// 위, 아래,왼쪽,오른쪽
int main()
{
    int n,m,k,sx,sy;
    scanf("%d%d%d", &n,&m,&k);
    vector<vector<int>> board;
    board.assign(n, vector<int>(m));
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        board[x][y] = 1;
    }
    scanf("%d%d", &sx, &sy);
    vector<int> d;
    d.assign(4,0);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &d[i]);
        d[i]--;
    }
    vector<vector<bool>> visited;
    visited.assign(n, vector<bool>(m, false));
    int idx = 0;
    visited[sx][sy] = true;
        int cnt = 0;
        for (int i = idx;; i++) {
            i %= 4;
            int nx = sx + gox[d[i]], ny = sy + goy[d[i]];
            if (cnt == 4) {
                break;
            }
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 1 || visited[nx][ny]) {
                cnt++;
                continue;
            }
            else {
                cnt = 0;
                while (sx + gox[d[i]] >= 0 && sx + gox[d[i]] < n && sy + goy[d[i]] >= 0 && 
                    sy + goy[d[i]] < m && board[sx + gox[d[i]]][sy + goy[d[i]]] == 0 && !visited[sx + gox[d[i]]][sy + goy[d[i]]]) {
                    sx += gox[d[i]];
                    sy += goy[d[i]];
                    visited[sx][sy] = true;
                }
            }
        }
        printf("%d %d\n", sx, sy);
    return 0;
}