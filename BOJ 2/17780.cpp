#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
struct pos{
    int num;
    int dir;
};
struct p{
    int x;
    int y;
};
int board[12][12];
int check(vector<p> &position){
    map<pair<int,int>,int> m;
    for(int i = 1 ;i< position.size();i++) {
        int x = position[i].x, y = position[i].y;
        m[{x,y}]++;
        if(m[{x,y}] >= 4) return 1;
    }
    return 0;
}
vector<p> resetposition(vector<p> &position,vector<vector<vector<pos>>> &v,int k){
    position.clear();
    position.resize(k+1);
    for(int i =0 ;i<v.size();i++){
        for(int j =0 ;j<v[i].size();j++){
            for(int k =0 ; k<v[i][j].size();k++){
                position[v[i][j][k].num] = {i,j};
            }
        }
    }
    return position;
}
vector<vector<vector<pos>>> white(vector<vector<vector<pos>>> &v,int x,int y,int nx,int ny){
     for(int j = 0 ;j<v[x][y].size();j++) {
         int num = v[x][y][j].num, dir = v[x][y][j].dir;
         v[nx][ny].push_back({num,dir});
     }
     v[x][y].erase(v[x][y].begin(),v[x][y].end());
    return v;
}
vector<vector<vector<pos>>> red(vector<vector<vector<pos>>> &v,int x,int y,int nx,int ny){
    for(int j = v[x][y].size()-1;j >= 0;j--){
        int num = v[x][y][j].num, dir = v[x][y][j].dir;
        v[nx][ny].push_back({num,dir});
    }
    v[x][y].erase(v[x][y].begin(),v[x][y].end());
    return v;
}
void go(vector<vector<vector<pos>>> &v,int turn,int n,int k,vector<p> &position,int &ans){
    if(check(position)){
        ans = turn;
        return;
    }
    if(ans == -1 || ans != 0 ) return;
    if(turn > 1000){
        ans = -1;
        return;
    }
   //각 말의 턴을 봄
    for(int i = 1 ; i<position.size();i++) {
        int x = position[i].x , y = position[i].y;
        int dhorsenum = v[x][y][0].num, dhorsedir = v[x][y][0].dir;
        if(i != dhorsenum) continue; //맨아래의 말이 아닌경우 그냥 패스
        int nx = x+gox[dhorsedir], ny = y+goy[dhorsedir];
        //파랑색
        if(nx<0 || nx>=n || ny<0 || ny>=n){
            // 방향전환
                int num = v[x][y][0].num, dir = v[x][y][0].dir;
                if(dir == 0 ) v[x][y][0].dir = 1;
                else if(dir == 1) v[x][y][0].dir = 0;
                else if(dir == 2) v[x][y][0].dir = 3;
                else if(dir == 3) v[x][y][0].dir = 2;

            nx = x + gox[v[x][y][0].dir], ny = y + goy[v[x][y][0].dir];
            if(board[nx][ny] != 2){
                if(board[nx][ny] == 0){
                    v = white(v,x,y,nx,ny);
                }
                else {
                    v = red(v,x,y,nx,ny);
                }
            }
        }
        //흰색(가장 위에 올려놓는다)
        else if(board[nx][ny] == 0){
            v = white(v,x,y,nx,ny);
        }
        //빨강색
        else if(board[nx][ny] == 1) {
            v = red(v,x,y,nx,ny);
        }
        else if(board[nx][ny] == 2) {
            //방향을 바꾼후 한칸을 가야할때 파란색인 경우, 혹은 벗어난 경우
            // 방향전환
            int num = v[x][y][0].num, dir = v[x][y][0].dir;
            if(dir == 0 ) v[x][y][0].dir = 1;
            else if(dir == 1) v[x][y][0].dir = 0;
            else if(dir == 2) v[x][y][0].dir = 3;
            else if(dir == 3) v[x][y][0].dir = 2;

            nx = x + gox[v[x][y][0].dir], ny = y+goy[v[x][y][0].dir];
            if(nx <0 || nx>=n || ny<0 || ny>=n) {
                position = resetposition(position,v,k);
                continue;
            }
            if(board[nx][ny] != 2) {
                if(board[nx][ny] == 0){
                   v = white(v,x,y,nx,ny);
                }
                else {
                    v = red(v,x,y,nx,ny);
                }
            }
        }
        position = resetposition(position,v,k);
    }

    go(v,turn+1,n,k,position,ans);
}

int main() {
    int n,k,ans = 0;
    scanf("%d%d",&n,&k);
    for(int i = 0 ; i < n;i++) {
        for(int j = 0 ;j < n;j++) {
            scanf(" %d",&board[i][j]);
        }
    }
    vector<vector<vector<pos>>> v;
    vector<p> position;
    position.resize(k+1);
    v.assign(n,vector<vector<pos>>(n,vector<pos>(0,{0,0})));
    for(int i=1;i<=k;i++){
        int x,y,dir;
        scanf("%d%d%d",&x,&y,&dir);
        x--,y--,dir--;
        v[x][y].push_back({i,dir});
        position[i] = {x,y};
    }
    go(v,0,n,k,position,ans);
    printf("%d\n",ans);
    return 0;
}