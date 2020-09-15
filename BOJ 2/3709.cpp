#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int gox[4] = {0,1,0,-1};
int goy[4] = {1,0,-1,0};
struct p {
    int x, y;
};
int main()
{
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n, r;
        scanf("%d%d", &n, &r);
        vector<vector<int>> board;
        board.assign(n + 2, vector<int>(n + 2,0));
        vector<vector<bool>> visited;
        visited.assign(n + 2, vector<bool>(n + 2, false));
        vector<p> mirror;
        for (int i = 0; i < r; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            board[x][y] = 1;
            mirror.push_back({ x,y });
        }
        int sx, sy,dir=0;
        scanf("%d%d", &sx, &sy);
        if (sy == 0)dir = 0;
        if (sx == 0) dir = 1;
        if (sy == n + 1) dir = 2;
        if (sx == n + 1) dir = 3;
        bool check = false;
            while (sx + gox[dir] >= 0 && sx + gox[dir] <= n + 1 && sy + goy[dir] >= 0 && sy + goy[dir] <= n + 1) {
                sx += gox[dir];
                sy += goy[dir];
                if (sx <= 0 || sx >= n + 1 || sy <= 0 || sy >= n + 1) {
                    check = true;
                    break;
                }
                if (board[sx][sy] == 1) {
                    dir++;
                    dir %= 4;
                    if (!visited[sx][sy]) {
                        visited[sx][sy] = true;
                    }
                }
            }
            if (check) printf("%d %d\n", sx, sy);
            else printf("0 0\n");
    }
    return 0;
}