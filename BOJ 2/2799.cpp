#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    char **board = new char*[5*n+1];
    for(int i=0;i<5*n+1;i++) board[i] = new char[5*m+1];
    for(int i=0;i<5*n+1;i++){
        for(int j=0;j<5*m+1;j++){
            scanf(" %c",&board[i][j]);
        }
    }
    int zero =0,one =0,two =0,three =0,four = 0;
    for(int i=1,k=0;k<n;i+=5,k++){
        for(int j=1,p=0;p<m;j+=5,p++){
            int star = 0;
            for(int a=0;a<4;a++){
                for(int b=0;b<4;b++){
                    if(board[i+a][j+b] == '*') star++;
                }
            }
            if(star ==0) zero++;
            else if(star == 4) one++;
            else if(star == 8) two++;
            else if(star == 12) three++;
            else four++;
        }
    }
    printf("%d %d %d %d %d\n",zero,one,two,three,four);
    for(int i=0;i<5*n+1;i++) delete[] board[i];
    delete[] board;
    return 0;
}