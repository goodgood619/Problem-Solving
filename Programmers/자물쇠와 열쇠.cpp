#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& key) {
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = key[m - j - 1][i];
        }
    }
    return temp;
}
vector<vector<int>> make(vector<vector<int>>& key,int x,int y) {
    //x번만큼 오른쪽이동, y번만큼 아래쪽이동
    int m = key.size();
    vector<vector<int>> temp;
    temp.assign(key.size(), vector<int>(key[0].size(), 0));
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key[i].size(); j++) {
            if(i+x<m && j+y<m) temp[i+x][j+y] = key[i][j];
        }
    }
    return temp;
}
bool ok(vector<vector<int>>& board,int m,int n) {
    for (int i = m; i < m+n; i++) {
        for (int j = m; j < m+n; j++) {
            if (board[i][j] == 0 || board[i][j]>=2) return false;
        }
    }
    return true;
}
bool same(vector<vector<int>> &key,vector<vector<int>> &lock,vector<vector<int>> &board) {
    int diff = lock.size() - key.size();
    for (int i = 0; i < board.size() - key.size(); i++) {
        for (int j = 0; j < board.size()-key.size(); j++) {
            vector<vector<int>> temp = board;
            for (int k = 0; k < key.size(); k++) {
                for (int q = 0; q < key[k].size(); q++) {
                    temp[i+k][j+q] += key[k][q];
                }
            }
            if (ok(temp,key.size(),lock.size())) return true;
        }
    }
    return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int m = key.size();
    int n = lock.size();
    vector<vector<int>> board;
    board.assign(n + (m - 1) * 2, vector<int>(n + (m - 1) * 2, 0));
    for (int i = m; i < m + n; i++) {
        for (int j = m; j < m + n; j++) {
            board[i][j] = lock[i - m][j - m];
        }
    }
    // 시계방향을 4번 돌려보기
    vector<vector<int>> temp = key;
    vector<vector<int>> temp2;
    for (int i = 0; i < 4; i++) {
        //rotate 후 위치를 다 옮겨보기
        temp = rotate(temp);
        //temp2를 가지고 움직여서 체크를 해보기
        for (int i = 0; i <= m - 1; i++) {
            for (int j = 0; j <= m - 1; j++) {
                temp2 = make(temp,i,j);
                if (same(temp2, lock,board)) {
                    return true;
                }
            }
        }
    }
    return false;
}