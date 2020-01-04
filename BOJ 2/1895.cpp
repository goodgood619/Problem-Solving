#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void go(int** &board,Int a,Int b,Int &ans,Int t) {
    vector<int> v;
    for(int i=a;i<a+3;i++) {
        for(int j=b;j<b+3;j++) {
            v.push_back(board[i][j]);
        }
    }
    sort(v.begin(),v.end());
    if(v[4]>=t) ans++;
}
int main() {
    Int n,m,t;
    scanf("%d%d",&n,&m);
    int **board = new int*[n];
    for(int i=0;i<n;i++) board[i] = new int[m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %d",&board[i][j]);
        }
    }
    scanf("%d",&t);
    Int ans = 0;
    for(int i=0;i<n-2;i++) {
        for(int j=0;j<m-2;j++) {
            go(board,i,j,ans,t);
        }
    }
    printf("%d",ans);
    for(int i=0;i<n;i++) delete[] board[i];
    delete[] board;
    return 0;
}