#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,1,0,-1};
int goy[4] = {1,0,-1,0};
void dfs(char **board, bool **visited,int x,int y,int a,int b,int dist,int &ans,int cnt,int total){
    visited[x][y] = true;
    if(cnt == total){
        ans = min(ans,dist);
        return;
    }
        for(int i=0;i<4;i++){
            i %= 4;
            int nx = x+gox[i],ny = y+goy[i];
            while(nx>=0 && nx<a && ny>=0 && ny<b && board[nx][ny] == '.' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                nx += gox[i], ny+= goy[i];
                cnt++;
            }
            nx -=gox[i], ny-=goy[i];
            if(nx != x || ny!= y) {
                dfs(board, visited, nx, ny, a, b, dist + 1, ans, cnt, total);
            }
            while (nx != x || ny != y) {
                    cnt--;
                    visited[nx][ny] = false;
                    nx -= gox[i], ny -= goy[i];
            }
    }
    visited[x][y] = false;
}
int main() {
    int a,b,t = 1;
    while(~scanf("%d%d",&a,&b)){
        char **board = new char*[a];
        bool **visited = new bool*[a];
        for(int i=0;i<a;i++) board[i] = new char[b],visited[i] = new bool[b];
        int total = 0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                scanf(" %c",&board[i][j]);
                if(board[i][j] =='.') total++;
                visited[i][j] = false;
            }
        }

        int ans = 1e9;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(board[i][j]=='.'){
                    dfs(board,visited,i,j,a,b,0,ans,1,total);
                }
            }
        }
        ans ==1e9 ? printf("Case %d: %d\n",t++,-1) : printf("Case %d: %d\n",t++,ans);
        for(int i=0;i<a;i++) delete[] board[i];
        delete[] board;
    }
    return 0;
}