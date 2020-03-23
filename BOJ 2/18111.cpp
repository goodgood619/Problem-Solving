#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef int64_t ll;
int main() {
    int n, m, b,minheight=1e9,maxheight=0;
    scanf("%d%d%d", &n, &m, &b);
    int** board = new int*[n];
    for (int i = 0; i < n; i++) board[i] = new int[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &board[i][j]);
            minheight = min(minheight, board[i][j]);
            maxheight = max(maxheight, board[i][j]);
        }
    }
    int minTime = 1e9, height = 0;
    for (int k = maxheight; k >= minheight; k--) {
        int buildcnt = 0, removecnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diff = board[i][j] - k;
                if (diff < 0) buildcnt = buildcnt - diff;
                else removecnt += diff;
            }
        }

        if (removecnt + b >= buildcnt) {
            int time = removecnt * 2 + buildcnt;
            if (time < minTime) {
                minTime = time;
                height = k;
            }
        }
    }
    printf("%d %d", minTime, height);
    delete[] board;
    return 0;
}