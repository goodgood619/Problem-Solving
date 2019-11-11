#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
struct pos{
    int s;
    int x;
    int y;
};
int main() {
    int n,t;
    scanf("%d%d",&n,&t);
    vector <pos> v;
    for(int i = 0 ;i<n;i++ ){
        int s,x,y;
        scanf("%d%d%d",&s,&x,&y);
        v.push_back({s,x,y});
    }

    int **board = new int*[n+1];
    for(int i=0;i <= n;i++) board[i] = new int[n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n ;j++){
            if(i == j) board[i][j] = 0;
            else board[i][j] = 1e9;
        }
    }

    for(int i = 0 ;i<v.size(); i++) {
        int is = v[i].s,sx = v[i].x, sy = v[i].y;
        for(int j =0 ; j<v.size(); j++){
            int js = v[j].s, tx = v[j].x, ty = v[j].y;
            if(i == j) continue;
            if(is ==1 && js == 1){
                board[i+1][j+1] = min(abs(sx-tx)+abs(sy-ty),t);
            }
            else board[i+1][j+1] = min(board[i+1][j+1],abs(sx-tx)+abs(sy-ty));
        }
    }

    for(int k = 1 ; k<=n ; k++) {
        for(int i = 1;i<=n; i++) {
            for(int j = 1 ; j<=n; j++) {
                if(i==j) continue;
                if(board[i][j]> board[i][k]+board[k][j]) board[i][j] = board[i][k] + board[k][j];
            }
        }
    }
    int m;
    scanf("%d",&m);
    for(int i = 0 ;i<m; i++){
        int here,next;
        scanf("%d%d",&here,&next);
        printf("%d\n",board[here][next]);
    }
    for(int i = 0 ;i<=n ; i++) delete[] board[i];
    delete[] board;
    v.clear();
    return 0;
}