#include <cstdio>
#include <algorithm>
using namespace std;
int n;
char board[55][55];
int main(){
	scanf("%d", &n);
	if (n % 2 == 0) printf("I LOVE CBNU\n");
	else{
		for (int i = 1; i < 54; i++) {
			for (int j = 1; j< 54; j++) {
				board[i][j] = ' ';
			}
		}
		for (int i = 1; i <= n; i++) {
			board[1][i] = '*';
		}
		int left = 1;
		int right = n;
		int mid = n / 2 + 1;
		board[2][mid] = '*';
		int nleft = mid - 1;
		int nright = mid + 1;
		int idx = 0;
		for (int i=3;;i++){
			board[i][nleft] = '*';
			board[i][nright] = '*';
			nleft--;
			nright++;
			if (nleft<1 && nright>n){
				idx = i;
				break;
			}
		}

		for (int i = 1; i <= idx; i++){
			int cnt = 0;
			for (int j = 1; j <= n; j++){
				if (i == 2 && cnt == 1) break;
				else if (i >= 3 && cnt == 2) break;
				printf("%c", board[i][j]);
				if(board[i][j]=='*') cnt++;
			}
			printf("\n");
		}
	}
	return 0;
}