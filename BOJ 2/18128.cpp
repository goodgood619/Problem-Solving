#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[8] = {0,0,-1,1,1,1,-1,-1};
int goy[8] = {1,-1,0,0,-1,1,-1,1};
bool visited[1000][1000];
bool manvisit[1000][1000];
struct p{
    int x;
    int y;
};
struct pos{
    int x,y,dist;
};
void spread(int mid,int n,vector<p> &water){
    queue<pos> q;
    for(int i=0;i<water.size();i++) {
        int x= water[i].x, y = water[i].y;
        x--,y--;
        q.push({x,y,0});
        visited[x][y] = true;
    }
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+gox[i], ny = y+goy[i];
            if(nx<0 || nx >= n  || ny<0 || ny >= n || visited[nx][ny] || dist+1 > mid) continue;
            else {
                if(nx == n-1 && ny == n-1){
                    continue;
                }
                else {
                    visited[nx][ny] = true;
                    q.push({nx, ny, dist + 1});
                }
            }
        }
    }
}
int bfs(int x,int y,int n,int **board){
    queue<p> q;
    q.push({x,y});
    manvisit[x][y] = true;
    int temp = 0;
    while(!q.empty()){
        int x= q.front().x;
        int y = q.front().y;
        if(x == n-1 && y == n-1){
            temp = 1;
            break;
        }
        q.pop();
        for(int i=0;i<8;i++){
            int nx = x+gox[i],ny = y+goy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || manvisit[nx][ny] || board[nx][ny] == 0) continue;
            else {
                if(!visited[nx][ny] && nx== n-1 && ny==n-1){
                    q.push({nx,ny});
                    continue;
                }
                else if(visited[nx][ny]) {
                    manvisit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    if(temp == 0) return 0;
    else return temp;
}
int main() {
    int n,w;
    scanf("%d%d",&n,&w);
    vector<p> water;
    int **board = new int*[n];
    for(int i=0;i<n;i++) board[i] = new int[n];
    for(int i=0;i<w;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        water.push_back({x,y});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %1d",&board[i][j]);
        }
    }
    int left = 0, right = 4000,ans = 4000;
    while(left<=right){
        memset(visited,false,sizeof(visited));
        memset(manvisit,false,sizeof(manvisit));
        int mid = (left+right)/2;
        spread(mid,n,water);
        if(bfs(0,0,n,board)){
            ans = min(ans,mid);
            right= mid-1;
        }
        else left = mid+1;
    }
    ans == 4000? printf("-1\n") : printf("%d\n",ans);
    for(int i=0;i<n;i++) delete[] board[i];
    delete[] board;
    return 0;
}