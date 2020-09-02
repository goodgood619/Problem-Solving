#include <string>
#include <vector>

using namespace std;

bool check(int m,int n,vector<string> &board) {
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            char one = board[i][j], two = board[i][j + 1], three = board[i + 1][j], four = board[i + 1][j + 1];
            if (one == two && two == three && three && four && four == one && one!='0') {
                return false;
            }
        }
    }
    return true;
}
void down(int m, int n, vector<string>& board) {
    for (int j = 0; j < n; j++) {
        for (int i = m - 1; i >= 0; i--) {
            if (board[i][j] == '0') {
                for (int k = i; k >= 0; k--) {
                    char one = board[k][j];
                    if (one == '0') continue;
                    else {
                        board[i][j] = one;
                        board[k][j] = '0';
                        break;
                    }
                }
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (true) {
        if (check(m,n,board)) break;
        vector<vector<int>> temp;
        temp.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                char one = board[i][j],two = board[i][j+1],three = board[i+1][j],four = board[i+1][j+1];
                if (one == two && two == three && three && four && four == one && one !='0') {
                    temp[i][j]++;
                    temp[i][j + 1]++;
                    temp[i + 1][j]++;
                    temp[i + 1][j + 1]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][j] > 0) {
                    answer++;
                    board[i][j] = '0';
                }
            }
        }
        down(m,n,board);
    }
    return answer;
}