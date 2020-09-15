#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct p {
    int x, y;
};
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
void left(int height,vector<vector<char>> &board,int m) {
    for (int i = 0;i<m; i++) {
        if (board[height][i] == 'x') {
            board[height][i] = '.';
            break;
        }
   }

}
void right(int height, vector<vector<char>>& board,int m) {
    for (int i = m-1;i>=0; i--) {
        if (board[height][i] == 'x') {
            board[height][i] = '.';
            break;
        }
    }
}
vector<p> bfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited,int n,int m) {
    queue<p> q;
    q.push({ x,y });
    visited[x][y] = true;
    vector<p> path;
    path.push_back({ x,y });
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '.' || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({ nx,ny });
            path.push_back({ nx,ny });
        }
    }
    return path;
}
bool compare(const p& a, const p &b) {
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y < b.y;
}
void down(vector<p>& cluster, vector<vector<char>>& board,int n) {
    vector<vector<char>> temp = board;
    vector<p> tempcluster;
    while (true) {
        bool stop = false;
        for (int i = 0; i < cluster.size(); i++) {
            int x = cluster[i].x, y = cluster[i].y;
            if (x + 1 < n && temp[x + 1][y] == '.') {
                temp[x + 1][y] = 'x';
                tempcluster.push_back({ x + 1,y });
                temp[x][y] = '.';
            }
            else {
                stop = true;
                break;
            }
        }
        if (stop) {
            break;
        }
        board = temp;
        cluster = tempcluster;
        tempcluster.clear();
        sort(cluster.begin(),cluster.end(),compare);
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<char>> board;
    board.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    vector<int> order;
    int r;
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        int num;
        scanf("%d", &num);
        order.push_back(num);
    }
    for (int i = 0; i < order.size(); i++) {
        if (i % 2 == 0) left(n-order[i],board,m);
        else right(n-order[i],board,m);

        vector<vector<bool>> visited;
        visited.assign(n, vector<bool>(m, false));
        for (int j = 0; j < m; j++) {
            if (!visited[n - 1][j]) {
                bfs(n - 1, j, board, visited,n,m);
            }
        }
        vector<p> cluster;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'x') {
                    cluster = bfs(i, j,board,visited,n,m);
                    break;
                }
            }
        }

        sort(cluster.begin(), cluster.end(), compare);
        if(cluster.size()>0) down(cluster, board,n);
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}