#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// 1:위, 2:아래, 3:왼쪽, 4: 오른쪽
// 이동을 한다. 그러나 동시에 여러상어가 들어올수있기때문에 상어의 새로운위치만을 넣어주고, 움직이지는 않는다
// 이동을 할때, 우선순위에 의거하여, 1. 냄새가 없는쪽, 2. 있다면 자기 냄새쪽으로 방향만 잡아준다
// 냄새를 전부 지워준다(새롭게 방문해야할곳빼고)
// 이제 새로운 위치에 냄새를 집어넣는다
// 상어가 한마리만 남았는지 체크한다
int gox[5] = {0,-1,1,0,0};
int goy[5] = {0,0,0,-1,1};
struct p {
    int x, y, curDir;
};
struct pp {
    int x, y, shark, curDir;
};
struct ppp {
    int shark, smell;
};
bool check(vector<p> &shark) {
    int total = 0;
    for (int i = 1; i < shark.size(); i++) {
        int x = shark[i].x;
        if (x >= 0) total++;
    }
    if (total > 1) return false;
    return true;
}
bool compare(const pp& a, const pp& b) {
    if (a.shark != b.shark) return a.shark < b.shark;
}
void moveAndSmell(vector<vector<ppp>>& board, vector<p>& shark, vector<vector<vector<int>>>& sharkPriority, int n, int m, int k) {

    vector<pp> newPos; // 새롭게 이동할 상어의 정보를 반영
    vector<vector<bool>> visited; //위치정보값 save
    visited.assign(n, vector<bool>(n, false));
    for (int i = 1; i < shark.size(); i++) {
        int cx = shark[i].x, cy = shark[i].y, curDir = shark[i].curDir;
        if (cx == -1 || cy == -1) continue;
        vector<int> moveDir = sharkPriority[i][curDir];
        bool inter = false;
        int midx = -1;
        for (int j = 0; j < moveDir.size(); j++) {
            int tx = cx + gox[moveDir[j]], ty = cy + goy[moveDir[j]];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n || board[tx][ty].shark!=0) continue;
            else {
                inter = true;
                midx = j;
                break;
            }
        }
        if (inter) {
            newPos.push_back({cx+gox[moveDir[midx]],cy+goy[moveDir[midx]],i,moveDir[midx] });
            visited[cx + gox[moveDir[midx]]][cy + goy[moveDir[midx]]] = true;
        }
        else {
            for (int j = 0; j < moveDir.size(); j++) {
                int tx = cx + gox[moveDir[j]], ty = cy + goy[moveDir[j]];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n || board[tx][ty].shark != i) continue;
                else {
                    inter = true;
                    midx = j;
                    break;
                }
            }
            if (midx != -1) {
                newPos.push_back({ cx + gox[moveDir[midx]],cy + goy[moveDir[midx]],i,moveDir[midx] });
                visited[cx + gox[moveDir[midx]]][cy + goy[moveDir[midx]]] = true;
            }
        }
    }

    // 냄새제거
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (board[i][j].smell > 0) board[i][j].smell--;
                if (board[i][j].smell == 0) {
                    board[i][j].shark = 0;
                }
            }
        }
    }

    sort(newPos.begin(), newPos.end(), compare);
    //냄새투입
    //새롭게 될 위치를 board에 반영 그리고 shark위치옮김
    for (int i = 0; i < newPos.size(); i++) {
        int x = newPos[i].x, y = newPos[i].y, curDir = newPos[i].curDir, sharkidx = newPos[i].shark;
        if (board[x][y].shark == 0) {
            board[x][y].shark = sharkidx;
            board[x][y].smell = k;
            shark[sharkidx].x = x;
            shark[sharkidx].y = y;
            shark[sharkidx].curDir = curDir;
        }
        else {
            //다시 본인의 영역으로 들어간것
            if (sharkidx == board[x][y].shark) {
                shark[sharkidx].x = x;
                shark[sharkidx].y = y;
                shark[sharkidx].curDir = curDir;
                board[x][y].smell = k;
                board[x][y].shark = sharkidx;
            }
            else {
                shark[sharkidx].x = -1;
                shark[sharkidx].y = -1;
                shark[sharkidx].curDir = -1;
            }
        }
    }

}
int solution(vector<vector<ppp>> &board,vector<p> &shark,vector<vector<vector<int>>> &sharkPriority,int n,int m,int k,int time) {


    while (true) {
        if (check(shark) || time > 1000) {
            break;
        }
        moveAndSmell(board,shark,sharkPriority,n,m,k);
        time++;
    }
    return time;
}
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<ppp>> board;
    vector<vector<vector<int>>> sharkPriority;
    vector<p> shark;
    sharkPriority.assign(m + 1, vector<vector<int>>(5,vector<int>(4,0)));
    shark.assign(m + 1,p());
    board.assign(n, vector<ppp>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            scanf(" %d", &num);
            if (num > 0) {
                board[i][j].shark = num;
                board[i][j].smell = k;
                shark[num].x = i;
                shark[num].y = j;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf(" %d", &shark[i].curDir);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 0; k < 4; k++) {
                int num;
                scanf(" %d", &num);
                sharkPriority[i][j][k] = num;
            }
        }
    }
    int time = 0;

    int ans= solution(board,shark,sharkPriority,n,m,k,time);
    printf("%d\n", ans > 1000 ? -1 : ans);
    return 0;
}