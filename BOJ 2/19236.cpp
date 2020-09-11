#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int gox[8] = {-1,-1,0,1,1,1,0,-1};
int goy[8] = {0,-1,-1,-1,0,1,1,1};
struct p {
    int num, dir;
};
struct pp {
    int x, y,dir;
};
//dfs인데
// make와 back을 구현을 해야하고, make와 back은 상어가 먹은 흔적O,X
// board의 움직인 흔적과 아닌흔적 ㅇㅇ, temp로 copy해놓고 만들고 다시 대입하고 그래야되지뭐 ㅇㅇ
// 17이 상어번호
int total;
void SWAP(vector<vector<p>>& tempboard,vector<pp> &tempfish,int num,int nx, int ny,int x,int y) {
    p temp = tempboard[nx][ny];
    tempboard[nx][ny] = tempboard[x][y];
    tempboard[x][y] = temp;
    int cindex = -1;
    for (int i = 1; i < tempfish.size(); i++) {
        if (nx == tempfish[i].x && ny == tempfish[i].y) {
            cindex = i;
            break;
        }
    }
    // 단순위치만 바꿔야하는데 dir까지 변경
    int tx = tempfish[cindex].x;
    tempfish[cindex].x = tempfish[num].x;
    tempfish[num].x = tx;
    int ty = tempfish[cindex].y;
    tempfish[cindex].y = tempfish[num].y;
    tempfish[num].y = ty;
}
vector<int> findFish(int sx,int sy,int sDir,vector<pp> &tempfish,vector<vector<p>> &tempboard) {
    vector<int> fish;
    int cnt = 0;
    while (true) {
        if (sx + gox[sDir] >= 4 || sx + gox[sDir] < 0 || sy + goy[sDir] >= 4 || sy + goy[sDir] < 0) break;
        if (tempboard[sx + gox[sDir]][sy + goy[sDir]].num != 0) {
            ++cnt;
            sx += gox[sDir];
            sy += goy[sDir];
            fish.push_back(cnt);
        }
        else {
            ++cnt;
            sx += gox[sDir];
            sy += goy[sDir];
        }
    }
    return fish;

}
void dfs(int sx,int sy,int sDir,int sum,vector<vector<p>> &board,vector<pp> &fish) {
    vector<vector<p>> tempboard = board;
    vector<pp> tempfish = fish;
    //물고기 move
    for (int i = 1; i < fish.size(); i++) {
        int fx = tempfish[i].x, fy = tempfish[i].y, fdir = tempfish[i].dir; //이거 tempfish인데 fish로 실수
        if (fx == -1) continue;
        for (int j = 0; j < 8; j++) {
            int nx = fx + gox[fdir], ny = fy + goy[fdir];
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || tempboard[nx][ny].num == 17) {
                fdir++;
                fdir %= 8;
                continue;
            }
            else {
                //빈칸
                if (tempboard[nx][ny].num == 0) {
                    tempboard[nx][ny] = { i,fdir };
                    tempfish[i] = { nx,ny,fdir}; // 이동후 아래원래 위치는 없애야한다
                    tempboard[fx][fy] = { 0,0 }; //이거안했음
                 }
                else {
                    // fish들끼리 swap하기전에 fDir반영
                    tempfish[i].dir = fdir;
                    tempboard[fx][fy].dir = fdir; //이거안해서 삽질
                    SWAP(tempboard,tempfish,i, nx, ny,fx,fy);
                }
                break;
            }
        }
    }

    vector<int> res = findFish(sx, sy, sDir, tempfish,tempboard);
    if (res.size() == 0) {
        total = max(total, sum);
        return;
    }
    vector<vector<p>> originalBoard = tempboard;
    vector<pp> originalFish = tempfish;
    for (int i = 0; i < res.size(); i++) {
        // 상어가 먹고 dfs
        int snx = sx + gox[sDir] * res[i], sny = sy + goy[sDir] * res[i];
        int sndir = tempboard[snx][sny].dir;
        sum += tempboard[snx][sny].num;
        int originalNum = tempboard[snx][sny].num;
        tempfish[originalNum] = { -1,-1,-1 }; //죽은 물고기
        tempboard[snx][sny] = { 17,sndir };
        tempboard[sx][sy] = { 0,0 }; //이제 빈곳
        dfs(snx, sny, sndir,  sum,tempboard,tempfish);
        //복구
        sum -= originalNum;
        tempboard = originalBoard;
        tempfish = originalFish;
    }
}
int main()
{   
    vector<vector<p>> board;
    vector<pp> fish;
    board.assign(4, vector<p>(4, {0,0}));
    fish.assign(17, pp{ 0,0,0 });
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int num, dir;
            scanf("%d%d", &num, &dir);
            board[i][j] = { num,--dir };
            fish[num] = { i,j,dir };
            if (i == 0 && j == 0) {
                fish[num] = { -1,-1,-1 };
            }
        }
    }
    total += board[0][0].num;
    int sx = 0, sy = 0,sDir = board[0][0].dir;
    board[0][0].num = 17;
    
    dfs(sx, sy, sDir, total, board,fish);
    printf("%d\n", total);
    return 0;
}