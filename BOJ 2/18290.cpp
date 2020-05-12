#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
using namespace std;
typedef int64_t ll;
int ans = -1e9;
void go(int here, int cnt, int depth, vector<vector<int>>& board, vector<int>& v, int total, vector<bool>& visited, int m) {
    if (cnt == depth) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            int x = v[i] / m, y = v[i] % m;
            sum += board[x][y];
            for (int j = i + 1; j < v.size(); j++) {
                int x = v[i] / m, y = v[i] % m, nx = v[j] / m, ny = v[j] % m;
                if (abs(x - nx) + abs(y - ny) <= 1) return;
            }
        }
        ans = max(ans, sum);
        return;
    }
    for (int i = here; i < total; i++) {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(i);
            go(i + 1, cnt + 1, depth, board, v, total, visited, m);
            v.pop_back();
            visited[i] = false;
        }
    }
}
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<int>> board;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &board[i][j]);
        }
    }
    vector<int> v;
    vector<bool> visited;
    visited.assign(n*m,false);
    go(0, 0, k, board, v, n * m, visited, m);
    printf("%d\n", ans);
    board.clear();
    visited.clear();
    v.clear();
    return 0;
}