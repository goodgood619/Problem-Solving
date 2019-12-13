#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void print(char** &board,int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}
int main() {
    Int n;
    scanf("%d",&n);
    char **board = new char*[n];
    for(int i=0;i<n;i++) board[i] = new char[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %c",&board[i][j]);
        }
    }
    Int choice;
    scanf("%d",&choice);
    if(choice == 1) {
        print(board,n);
    }
    else if(choice == 2) {
        char ** newboard = new char*[n];
        for(int i=0;i<n;i++) newboard[i] = new char[n];
        for(int i=0;i<n;i++){
            for(int j=n-1,k=0;j>=0;j--,k++){
                newboard[i][k] = board[i][j];
            }
        }
        print(newboard,n);
        for(int i=0;i<n;i++) delete newboard[i];
        delete newboard;
    }
    else {
        char ** newboard = new char*[n];
        for(int i=0;i<n;i++) newboard[i] = new char[n];
        for(int i=n-1,k=0;i>=0;i--,k++){
            for(int j=0;j<n;j++){
                newboard[k][j] = board[i][j];
            }
        }
        print(newboard,n);
        for(int i=0;i<n;i++) delete newboard[i];
        delete newboard;
    }
    for(int i=0;i<n;i++) delete board[i];
    delete board;
    return 0;
}