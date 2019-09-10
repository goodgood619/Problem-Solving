#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int n;
ll board[12][12];
ll sum;
void gogo() {
	for (int i = 1; i <= n; i++) {
		sum += board[i][1];
	}
	for (int j = 1; j <= n; j++) {
		sum += board[n][j];
	}
	for (int i = n, j = n; i >= 1 && j >= 1; i--, j--) {
		sum += board[i][j];
	}
	sum -= board[1][1];
	sum -= board[n][1];
	sum -= board[n][n];
}
int main(){
	int Case = 1;
	while (1){
		sum = 0;
		memset(board, 0, sizeof(board));
		scanf("%d", &n);
		if (n == 0) break;
		else{
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= i; j++){
					scanf(" %lld", &board[i][j]);
				}
			}
			if (n == 1) {
				printf("Case #%d:%lld\n", Case,board[1][1]);
				Case++;
			}
			else {
				gogo();
				printf("Case #%d:%lld\n", Case, sum);
				Case++;
			}
		}
	}
	return 0;
}