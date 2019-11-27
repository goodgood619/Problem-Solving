#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[8] = {0,0,-1,1,1,1,-1,-1};
int goy[8] = {1,-1,0,0,-1,1,-1,1};
struct p{
    int x;
    int y;
};
void bfs(int r,int c,char **board,int n){
    bool **visited = new bool*[n+1];
    for(int i=1;i<=n;i++) visited[i] = new bool[n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visited[i][j] = false;
        }
    }
    visited[r][c] = true;
    board[r][c] = 'v';
    queue<p> q;
    q.push({r,c});
    while(!q.empty()){
        int x= q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i=4;i<8;i++){
            int nx =x+gox[i],ny = y+goy[i];
            if(nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny]) continue;
            else {
                q.push({nx,ny});
                visited[nx][ny] = true;
                board[nx][ny] = 'v';
            }
        }
    }

    for(int i=1;i<=n;i++) delete[] visited[i];
    delete[] visited;
}
int main() {
    int n,r,c;
    scanf("%d%d%d",&n,&r,&c);
    char **board = new char*[n+1];
    for(int i=1;i<=n;i++) board[i] = new char[n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            board[i][j] = '.';
        }
    }
    bfs(r,c,board,n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++) delete[] board[i];
    delete[] board;
    return 0;
}