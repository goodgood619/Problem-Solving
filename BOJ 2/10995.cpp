#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
char board[150][300];
int main(){
	scanf("%d", &n);
	if (n == 1) printf("*\n");
	else {
		for(int i=1;i<=n;i++){
			int start = 0;
			int cnt = 1;
			if (i % 2 == 1) start = 1;
			else start = 2;
				for (int j = start;cnt<=n;j += 2){
					board[i][j] = '*';
					cnt++;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2*n; j++) {
				if (board[i][j] != '*') printf(" ");
				else if(board[i][j]=='*')printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}