#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int board[105][105];
int cnt[10005];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
			cnt[board[i][j]]++;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] >= 2) {
			printf("FALSE\n");
			return 0;
		}
	}
	bool no = false;
	int aim = n*(n*n + 1) / 2;
	for (int i = 1; i <= n; i++){
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += board[i][j];
		}
		if (sum == aim) continue;
		else {
			no = true;
			break;
		}
	}
	if (!no) {
		for (int j = 1; j <= n; j++) {
			int sum = 0;
			for (int i = 1; i <= n; i++) {
				sum += board[i][j];
			}
			if (sum == aim) continue;
			else {
				no = true;
				break;
			}
		}
		int what = 0;
		for (int i = 1, j = n; i <= n; i++, j--) {
			what += board[i][j];
		}
		if (what != aim) no = true;
		int what2 = 0;
		for (int i = 1; i <= n; i++) {
			what2 += board[i][i];
		}
		if (what2 != aim) no = true;
	}
	if (no) printf("FALSE\n");
	else printf("TRUE\n");
	return 0;
}