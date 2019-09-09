#include <stdio.h>
#include <algorithm>
using namespace std;
int m, n;
int U, L, R, D;
char board[20][20];
char word[15][20];
void makeboard(){
	bool check = false;
	bool check2 = false;
	for (int i = 0; i < n + U + D; i++){
		if (i != 0) {
			if (!check2) check2 = true;
			else check2 = false;
		}
		if (!check2) check = false;
		else check = true;
		for (int j = 0; j < m + L + R; j++) {
			if (!check){
				board[i][j] = '#';
				check = true;
			}
			else{
				board[i][j] = '.';
				check = false;
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &U, &L, &R, &D);
	for (int i = 0; i < n; i++) { scanf("%s", word[i]);}
	makeboard();

	int k = 0;
	int p = 0;
	for (int i = U; i<U+n; i++) {
		for (int j = L;word[k][p]!='\0'; j++) {
			board[i][j] = word[k][p];
			p++;
		}
		k++;
		p = 0;
	}
	for (int i = 0; i < n + U + D; i++) {
		for (int j = 0; j < m + L + R; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}