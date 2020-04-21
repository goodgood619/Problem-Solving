#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
using namespace std;
typedef int64_t ll;
bool first(int n, int m, vector<vector<int>>& board, vector<vector<int>>& sticker, int r, int c) {
    int ex = n - r, ey = m - c;
    if (ex < 0 || ey < 0) return false;
    int x = 0, y = 0;
    bool ok = false;
    while (true) {
        if (x > ex) break;
        int p = x;
        int q = y;
        bool no = false;
        for (int i = 0, a = p; i < r; i++, a++) {
            for (int j = 0, b = q; j < c; j++, b++) {
                if (board[a][b] == 1 && sticker[i][j] == 1) {
                    no = true;
                }
            }
        }
        if (!no) { //맞는것이 존재
            for (int i = x, a = 0; i < x + r; i++, a++) {
                for (int j = y, b = 0; j < y + c; j++, b++) {
                    if (sticker[a][b] == 1 && board[i][j] == 0)
                        board[i][j] = sticker[a][b];
                }
            }
            ok = true;
            break;
        }
        if (y == ey) {
            y = 0;
            x++;
        }
        else y++;
    }

    return ok;
}
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<int>> board;
    board.assign(n, vector<int>(m, 0));
    vector<vector<vector<int>>> sticker;
    for (int i = 0; i < k; i++) {
        int r, c;
        scanf("%d%d", &r, &c);
        vector<vector<int>> temp;
        temp.assign(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf(" %d", &temp[i][j]);
            }
        }
        sticker.push_back(temp);
    }

    for (auto e : sticker) {
        int r = e.size();
        int c = e[0].size();
        //1번
        if (first(n, m, board, e, r, c)) {
            continue;
        }

        //2번
        for (int i = 0; i < 3; i++) {
            vector<vector<int>> temp;
            if (i == 0) {
                temp.assign(c,vector<int>(r,0));
                for (int a = 0, q = 0; a < c; a++, q++) {
                    for (int b = 0, p = r - 1; b < r; b++, p--) {
                        temp[a][b] = e[p][q];
                    }
                }
                if (first(n, m, board, temp, c, r)) {
                    break;
                }
            }
            else if (i == 1) {
                temp.assign(r, vector<int>(c, 0));
                for (int a = 0, p = r - 1; a < r; a++, p--) {
                    for (int b = 0, q = c - 1; b < c; b++, q--) {
                        temp[a][b] = e[p][q];
                    }
                }
                if (first(n, m, board, temp, r, c)) {
                    break;
                }
            }
            else {
                temp.assign(c, vector<int>(r, 0));
                for (int a = 0, q = c - 1; a < c; a++, q--) {
                    for (int b = 0, p = 0; b < r; b++, p++) {
                        temp[a][b] = e[p][q];
                    }
                }
                if (first(n, m, board, temp, c, r)) {
                    break;
                }
            }
        }

    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
