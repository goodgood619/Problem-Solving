#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int gox[4] = {0,-1,1,0};
int goy[4] = {1,0,0,-1};
struct p {
    int x, y;
};
int ccw(p A, p B, p C) {
    int x1 = A.x, y1 = A.y, x2 = B.x, y2 = B.y, x3 = C.x, y3 = C.y;
    return (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<char>> board;
    board.assign(n, vector<char>(n));
    vector<p> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &board[i][j]);
            if (board[i][j] != '.') {
                v.push_back({ i,j });
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                if (ccw(v[i], v[j], v[k]) == 0) cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}