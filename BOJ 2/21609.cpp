#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int gox[4] = { 0, 1, -1, 0 };
int goy[4] = { 1, 0, 0, -1 };
struct p {
    int blockCnt, rainbowCnt, x, y;
    vector<pair<int, int>> pos;
};

void dfs(int x, int y, vector<pair<int, int>>& temp, vector<vector<int>>& board, vector<vector<bool>>& visited, int n,
    int num, vector<pair<int, int>>& rainbowTemp) {
    visited[x][y] = true;
    temp.push_back({ x, y });
    if (board[x][y] == 0) rainbowTemp.push_back({ x, y });
    for (int i = 0; i < 4; i++) {
        int nx = x + gox[i];
        int ny = y + goy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || board[nx][ny] == -100 ||
            board[nx][ny] == -1)
            continue;
        if (board[nx][ny] == 0 || board[nx][ny] == num) {
            dfs(nx, ny, temp, board, visited, n, num, rainbowTemp);
        }
    }
}

bool compare(const p& a, const p& b) {
    if (a.blockCnt != b.blockCnt) return a.blockCnt > b.blockCnt;
    if (a.rainbowCnt != b.rainbowCnt) return a.rainbowCnt > b.rainbowCnt;
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
}

void gravity(vector<vector<int>>& board) {
    int n = board.size();

    for (int j = n - 1; j >= 0; j--) {
        for (int i = n - 1; i >= 0; i--) {
            if (board[i][j] == -100) {
                queue<pair<int, pair<int, int>>> resArr;
                for (int k = i; k >= 0; k--) {
                    if (board[k][j] == -1) {
                        break;
                    }
                    else if (board[k][j] >= 0) {
                        resArr.push({ board[k][j], {k, j} });
                    }
                }

                int nx = i;
                int ny = j;
                while (!resArr.empty()) {
                    int tx = resArr.front().second.first;
                    int ty = resArr.front().second.second;
                    resArr.pop();
                    board[nx][ny] = board[tx][ty];
                    board[tx][ty] = -100;
                    nx--;
                }

                for (int k = nx; k >= 0; k--) {
                    if (board[k][j] != -1) {
                        board[k][j] = -100;
                    }
                    else break;
                }
            }
        }
    }
}

vector<vector<int>> rotate(vector<vector<int>>& board) {
    vector<vector<int>> newboard;
    int n = board.size();
    newboard.assign(n, vector<int>(n, 0));
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newboard[n-j-1][i] = board[i][j];
        }
    }

    return newboard;
}

void clearRainbow(vector<vector<bool>> &visited, vector<vector<int>> &board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) visited[i][j] = false;
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> board;
    board.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // 가장 큰 블록을 찾고, 정렬을 한다.
    int ans = 0;
    while (true) {
        vector<vector<int>> tempboard = board;
        vector<p> v;
        vector<vector<bool>> visited;
        visited.assign(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 0 && !visited[i][j]) {
                    vector<pair<int, int>> temp;
                    vector<pair<int, int>> rainbowTemp;
                    dfs(i, j, temp, board, visited, n, board[i][j], rainbowTemp);
                    if (temp.size() >= 2) {
                        v.push_back({ (int)temp.size(), (int)rainbowTemp.size(), i, j, temp });
                    }
                }

                clearRainbow(visited,board);
            }
        }

        sort(v.begin(), v.end(), compare);

        if (v.size() == 0) break; // 더이상 플레이 불가능
        ans += (v[0].blockCnt * v[0].blockCnt);

        // 제거한다.
        for (int i = 0; i < v[0].pos.size(); i++) {
            int x = v[0].pos[i].first;
            int y = v[0].pos[i].second;
            tempboard[x][y] = -100; // 제거된것은 -100으로 표현
        }

        //중력작용
        gravity(tempboard);
        // 90도 반시계 회전
        tempboard = rotate(tempboard);
        // 중력작용
        gravity(tempboard);

        board = tempboard;

    }

    printf("%d\n", ans);

    return 0;
}
