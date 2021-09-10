#include <cstdio>
#include <vector>
using namespace std;
int check(vector<vector<int>>& board, int choice) {
    int res = 0;
    if (choice == 0) {
        for (int j = 6; j < 10; j++) {
            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                if (board[i][j] == 1) {
                    cnt++;
                }
            }
            if (cnt == 4) {
                res++;
            }
        }
    }
    else {
        for (int i = 6; i < 10; i++) {
            int cnt = 0;
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == 1) {
                    cnt++;
                }
            }
            if (cnt == 4) res++;
        }
    }

    return res;

}

void move_blue(vector<vector<int>>& board, int t, int x, int y) {
    int sx = x;
    int sy = y;
    if (t == 1) {
        while (sy +1 <=9 && board[sx][sy+1] == 0) {
            sy++;
        }
        board[x][y] = 0;
        board[sx][sy] = 1;
    }
    else if (t == 2) {
        while (sy + 2 <= 9 && board[sx][sy+2] == 0) {
            sy++;
        }
        board[x][y] = 0;
        board[x][y + 1] = 0;

        board[sx][sy] = 1;
        board[sx][sy + 1] = 1;
    }
    else {
        while (sy + 1<=9 && board[sx][sy+1] == 0 && board[sx + 1][sy+1] == 0) {
            sy++;
        }
        board[x][y] = 0;
        board[x + 1][y] = 0;

        board[sx][sy] = 1;
        board[sx + 1][sy] = 1;
    }
}
void move_green(vector<vector<int>>& board, int t, int x, int y) {
    int sx = x;
    int sy = y;
    if (t == 1) {
        while (sx + 1 <=9 && board[sx+1][sy] == 0) {
            sx++;
        }
        board[x][y] = 0;
        board[sx][sy] = 1;
    }
    else if (t == 2) {
        while (sx +1 <=9 && board[sx+1][sy + 1] == 0 && board[sx+1][sy] == 0) {
            sx++;
        }
        board[x][y] = 0;
        board[x][y + 1] = 0;

        board[sx][sy] = 1;
        board[sx][sy + 1] = 1;
    }
    else {
        while (sx + 2 <= 9 && board[sx + 2][sy] == 0) {
            sx++;
        }
        board[x][y] = 0;
        board[x + 1][y] = 0;

        board[sx][sy] = 1;
        board[sx + 1][sy] = 1;
    }
}

void repos_blue(vector<vector<int>>& board, int move) {

    for (int j = 9; j >= 6; j--) {
        int zeroCnt = 0;
        for (int i = 0; i < 4; i++) {
            if (board[i][j] == 1) {
                zeroCnt++;
            }
        }
        if (zeroCnt == 4) {
            for (int k = j - move; k >= 4; k--) {
                for (int i = 0; i < 4; i++) {
                    board[i][k + move] = board[i][k];
                    board[i][k] = 0;
                }
            }
            break;
        }
    }
}

void repos_green(vector<vector<int>>& board, int move) {

    for (int i = 9; i >= 6; i--) {
        int zeroCnt = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 1) {
                zeroCnt++;
            }
        }
        if (zeroCnt == 4) {
            for (int k = i - move; k >= 4; k--) {
                for (int j = 0; j < 4; j++) {
                    board[k + move][j] = board[k][j];
                    board[k][j] = 0;
                }
            }
            break;
        }
    }
}


int check_blue(vector<vector<int>>& board) {
    int res = 0;
    for (int j = 4; j < 6; j++) {
        for (int i = 0; i < 4; i++) {
            if (board[i][j] > 0) {
                res++;
                break;
            }
        }
    }

    return res;
}

int check_green(vector<vector<int>>& board) {
    int res = 0;
    for (int i = 4; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] > 0) {
                res++;
                break;
            }
        }
    }

    return res;
}

void erase_blue(vector<vector<int>>& board, int cnt) {

    for (int j = 9; j > 9 - cnt; j--) {
        for (int i = 0; i < 4; i++) {
            board[i][j] = 0;
        }
    }
}

void erase_green(vector<vector<int>>& board, int cnt) {

    for (int i = 9; i > 9 - cnt; i--) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
}

void move_blue_last(vector<vector<int>>& board, int cnt) {
    for (int k = 9 - cnt; k >= 4; k--) {
        for (int i = 0; i < 4; i++) {
            board[i][k + cnt] = board[i][k];
            board[i][k] = 0;
        }
    }
}

void move_green_last(vector<vector<int>>& board, int cnt) {
    for (int i = 9 - cnt; i >= 4; i--) {
        for (int j = 0; j < 4; j++) {
            board[i + cnt][j] = board[i][j];
            board[i][j] = 0;
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> board;
    board.assign(10, vector<int>(10, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (t == 1) {
            board[x][y] = 1;
        }
        else if (t == 2) {
            board[x][y] = 1;
            board[x][y + 1] = 1;
        }
        else {
            board[x][y] = 1;
            board[x + 1][y] = 1;
        }

        // 파란색 이동 (열)

        // 1. 빨간색 영역에서 블록이동
        move_blue(board, t, x, y);
        // 2. (6 7 8 9) (0 1 2 3)에 4줄이 있는지 체크

        int resRed = check(board, 0);
        // 2-1 : 4줄이 있으면 그 줄은 전부 지우고, 다시 재조정 (연한칸에 블록이 있는 경우도 내려야한다)
        if (resRed > 0) {
            cnt += resRed;
            repos_blue(board, resRed);
        }
        // 3. 연한 파란색 영역 (4 5) (0 1 2 3)에 있는지 체크
        int resblue1 = check_blue(board);
        // 4. 3번에서 만약 있다면, 끝에서 그 열을 지움
        if (resblue1 > 0) {
            erase_blue(board, resblue1);
            move_blue_last(board, resblue1);
        }
        // 5. 4번에서 지운 열만큼 최종 형태 다시 만들기 위해 오른쪽으로 이동
//        move_blue_last(board,resblue1);


        // 초록색 이동 (행)

        move_green(board, t, x, y);

        int resGreen = check(board, 1);

        if (resGreen > 0) {
            cnt += resGreen;
            repos_green(board, resGreen);
        }

        int resGreen1 = check_green(board);

        if (resGreen1 > 0) {
            erase_green(board, resGreen1);
            move_green_last(board, resGreen1);
        }

        //        move_green_last(board,resGreen1);
    }

    printf("%d\n", cnt);
    int ans = 0;
    for (int i = 4; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) ans++;
        }
    }

    for (int j = 4; j < 10; j++) {
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != 0) ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}