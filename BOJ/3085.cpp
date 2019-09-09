#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char board[55][55];
int n,ans=1;
int gox[2] = {0,1};
int goy[2] = {1,0};
void swap(int i,int j,int nx,int ny){
	char temp=board[i][j];
	board[i][j] = board[nx][ny];
	board[nx][ny] = temp;
}
void check(){
	int ret = 1;
	for (int i = 1; i <= n; i++) {
		ret = 1;
		for (int j = 1; j <= n-1; j++){
			if (board[i][j] == board[i][j + 1]){
				ret++;
				ans = max(ans, ret);
			}
			else{
				ret = 1;
				ans = max(ans, ret);
			}
		}
	}
	ret = 1;
	for (int j = 1; j <= n; j++) {
		ret = 1;
		for (int i = 1; i <= n - 1; i++) {
			if (board[i][j] == board[i + 1][j]) {
				ret++;
				ans = max(ans, ret);
			}
			else {
				ret = 1;
				ans = max(ans, ret);
			}
		}
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				int nx = i + gox[k];
				int ny = j + goy[k];
				if (nx > n || ny > n) continue;
				swap(i,j,nx,ny);
				check();
				swap(i,j,nx,ny);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}