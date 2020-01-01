#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n,m;
    scanf("%d%d",&n,&m);
    char **board = new char*[n];
    for(int i=0;i<n;i++) board[i] = new char[m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            board[i][j] = '.';
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            scanf(" %c",&board[i][j]);
        }
    }

    for(int j=m-1;j>=0;j--) {
        for(int i=0;i<n;i++){
            if (board[i][j] == '.')    printf(".");
            else if (board[i][j] == 'O')    printf("O");
            else if (board[i][j] == '-')    printf("|");
            else if (board[i][j] == '|')    printf("-");
            else if (board[i][j] == '/')    printf("\\");
            else if (board[i][j] == '\\')   printf("/");
            else if (board[i][j] == '^')    printf("<");
            else if (board[i][j] == '<')    printf("v");
            else if (board[i][j] == 'v')    printf(">");
            else if (board[i][j] == '>')    printf("^");
        }
        printf("\n");
    }
    for(int i=0;i<n;i++) delete board[i];
    delete[] board;
    return 0;
}