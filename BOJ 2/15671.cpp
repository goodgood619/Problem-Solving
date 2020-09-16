#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int gox[8] = {0,1,0,-1,1,1,-1,-1};
int goy[8] = {1,0,-1,0,1,-1,-1,1};
struct p {
    int x, y;
};
void print(vector<vector<int>>& board,int &white,int &black) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (board[i][j] == 1) {
                printf("B");
                black++;
            }
            else if (board[i][j] == 2) {
                printf("W");
                white++;
            }
            else printf(".");
        }
        printf("\n");
    }
}
// 가능한거 다뒤집는거네 ㅇㅇ
void clean(vector<vector<int>>& board,int x,int y,int choice) {
    vector<vector<int>> temp = board;
    vector<int> p,p2;
    int dir = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + gox[i], ny = y + goy[i];
        if (nx < 0 || nx >= 6 || ny < 0 || ny >= 6 || board[nx][ny] == 0 || board[nx][ny]==choice) continue;
        else {
            p.push_back(i);
        }
    }
    for (auto d : p) {
        int sx = x+gox[d], sy = y+goy[d],check=-1;
        while (true) {
            if (sx < 0 || sx >= 6 || sy < 0 || sy >= 6 || board[sx][sy]==0) {
                check = 0;
                break;
            }
            if (board[sx][sy] == choice) {
                check = 1;
                break;
            }
            sx += gox[d];
            sy += goy[d];
        }
        if (check==1) p2.push_back(d);
    }
    for (auto d : p2) {
        int sx = x, sy = y;
        while (sx + gox[d] < 6 && sx + gox[d] >= 0 && sy + goy[d] < 6 && sy + goy[d] >= 0 && board[sx + gox[d]][sy + goy[d]] != choice && board[sx + gox[d]][sy + goy[d]] != 0) {
            sx += gox[d];
            sy += goy[d];
            board[sx][sy] = choice;
        }
    }
}
// 흑 : 1, 백 : 2
void make(vector<vector<int>>& board, int x, int y, int choice) {
    board[x][y] = choice;
    clean(board, x, y, choice);
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> board;
    board.assign(6, vector<int>(6, 0));
    board[2][2] = 2,board[3][3]=2,board[2][3]=1,board[3][2]=1;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        if (i % 2 == 0) {
            make(board,x,y,1);
        }
        else make(board,x,y,2);
    }
    int white = 0, black = 0;
    print(board,white,black);
    printf("%s\n", black < white ? "White": "Black");
    
    return 0;
}