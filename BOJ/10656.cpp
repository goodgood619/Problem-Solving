#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
char board[55][55];
typedef pair<int, int> P;
P anspo[3000];
int n, m,p;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char start = board[i][j];
			if (start == '#') continue;
			else {
				bool okcheck = false;
				if (j <=1 || (board[i][j - 1] == '#' && j > 1)){
					int cnt = 0;
					if (board[i][j + 1] == '.' && j+1<=m) cnt++;
					if (board[i][j + 2] == '.' && j+2<=m) cnt++;
					if (cnt >= 2) {
						anspo[p].first = i;
						anspo[p].second = j;
						p++;
						okcheck = true;
					}
				}
				if (okcheck) continue;
				if (i <=1 || (board[i - 1][j] == '#' && i > 1)){
					int cnt = 0;
					if (board[i+1][j] == '.' && i + 1 <=n) cnt++;
					if (board[i+2][j] == '.' && i + 2 <=n) cnt++;
					if (cnt >= 2) {
						anspo[p].first = i;
						anspo[p].second = j;
						p++;
					}
				}
			}
		}
	}
	printf("%d\n", p);
	for (int i = 0; i < p; i++) {
		printf("%d %d\n", anspo[i].first, anspo[i].second);
	}
	return 0;
}