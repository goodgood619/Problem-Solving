#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
struct p {
    int sx, sy, ex, ey;
};
struct pp {
    int index, gas;
};
struct ppp {
    int x, y, cost;
};
struct pppp {
    int x, y, cost, index;
};
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
bool compare(const pppp& a, const pppp& b) {
    if (a.cost != b.cost) return a.cost < b.cost;
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
}
void bfs(queue<ppp> &q,vector<vector<int>> &board,vector<vector<int>> &boardDist,vector<vector<bool>> &boardvisited,int n) {
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || boardvisited[nx][ny] || board[nx][ny] == 1) continue;
            boardvisited[nx][ny] = true;
            boardDist[nx][ny] = boardDist[x][y] + 1;
            q.push({ nx,ny,cost + 1 });
        }
    }
}
pp find(vector<vector<int>>& board, vector<p>& client, int n, int m, int gas, int tx, int ty,vector<bool> &visited) {
    queue<ppp> q;
    q.push({ tx,ty,0 });
    vector<vector<bool>> boardvisited;
    vector<vector<int>> boardDist;
    boardvisited.assign(n, vector<bool>(n, false));
    boardvisited[tx][ty] = true;
    boardDist.assign(n, vector<int>(n, 0));
    bfs(q, board, boardDist, boardvisited,n);
    vector<pppp> temp;
    for (int k = 0; k < client.size(); k++) {
        if (visited[k]) continue;
        int x = client[k].sx, y = client[k].sy;
        if (boardvisited[x][y]) temp.push_back({ x,y,boardDist[x][y],k });
        else if (!boardvisited[x][y] && board[x][y]==0) return { -1,-1 };
    }
    sort(temp.begin(), temp.end(), compare);
    if (gas > temp[0].cost) {
        gas -= temp[0].cost;
        tx = temp[0].x, ty = temp[0].y;
        int ex = client[temp[0].index].ex,ey = client[temp[0].index].ey;
        q.push({ tx,ty,0 });
        boardvisited.assign(n, vector<bool>(n, false));
        boardDist.assign(n, vector<int>(n, 0));
        boardvisited[tx][ty] = true;
        bfs(q, board, boardDist, boardvisited,n);
        if (gas < boardDist[ex][ey] || !boardvisited[ex][ey]) return { -1,-1 };
        else if(boardvisited[ex][ey] && board[ex][ey]==0){
            gas += boardDist[ex][ey];
            return { temp[0].index,gas };
        }
    }
    else {
        return { -1,-1 };
    }
}
bool check(vector<bool>& visited) {
    int total = 0;
    for (auto value : visited) {
        if (value) {
            total++;
        }
    }
    return total == visited.size();
}
int solution(vector<vector<int>> &board,vector<p> &client,int n,int m,int gas,int tx,int ty) {
    vector<bool> visited;
    visited.assign(m, false);
    bool no = false;
    while (true) {
        if (check(visited)) {
            break;
        }
        pp ret = find(board,client,  n,  m,  gas,tx,ty,visited);
        if (ret.index == -1) {
            no = true;
            break;
        }
        visited[ret.index] = true;
        gas = ret.gas;
        tx = client[ret.index].ex,ty = client[ret.index].ey;
    }
    if (no) return -1;
    return gas;
}
int main()
{
    int n, m, gas,tx,ty;
    scanf("%d%d%d", &n, &m, &gas);
    vector<vector<int>> board;
    vector<p> client;
    client.assign(m, p{ 0,0,0,0 });
    board.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    scanf("%d%d", &tx, &ty);
    tx--, ty--;
    for (int i = 0; i < m; i++) {
        int sx, sy, ex, ey;
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        sx--, sy--, ex--, ey--;
        client[i].sx = sx, client[i].sy = sy, client[i].ex = ex, client[i].ey = ey;
    }
    int ans = solution(board, client, n, m, gas, tx, ty);
    printf("%d\n", ans);
    return 0;
}