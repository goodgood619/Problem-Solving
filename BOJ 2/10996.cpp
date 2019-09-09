#include <cstdio>
#include <algorithm>
using namespace std;
char board[210][105];
int n;
int main(){
	scanf("%d", &n);
	if (n == 1) printf("*\n");
	else {
		for (int i = 1; i <=205; i++) {
			for (int j = 1; j <=103; j++) {
				board[i][j] = ' ';
			}
		}
		int i = 0;
		for (int j = 1; j <= n; j++){
			bool check = false;
			if (j % 2 == 1) check = false;
			else check = true;
			if (!check) i = 1;
			else i = 2;
			for (;i <= 2 * n; i += 2){
				board[i][j] = '*';
			}
		}
		for (int i = 1; i <= 2 * n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%c", board[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}