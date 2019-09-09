#include <stdio.h>
#include <algorithm>
using namespace std;
int r, c, a, b;
char board[150][150];
bool real;
int main(){
	scanf("%d%d", &r, &c);
	scanf("%d%d", &a, &b);
	bool check = false;
	for (int i = 1; i <= r*a; i++) {
		for (int j = 1; j <= c*b; j++){
			board[i][j] = '.';
		}
	}
	int p = b;
	int cnt = 1;
	for (int q = 0; q < r; q++){
		if (q != 0) {
			if (!check) check = true;
			else check = false;
		}
		real = check;
		for (int i = q*a + 1; i < (q+1)*(a) + 1; i++) {
			for (int j = 1; j <= c*b;) {
				if (!check && p != 0){
					board[i][j] = 'X';
					p--;
					if (j == c*b&& real == check){
						p = b;
					}
					else if (j == c*b && real != check) {
						p = b;
						check = true;
					}
					j++;
					continue;
				}
				else if(!check&& p==0){
						check = true;
						p = b;
						continue;
				}
				else if (check && p != 0){
					p--;
					if (j == c*b && real==check){
						p = b;
					}
					else if (j == c*b && real != check) {
						p = b;
						check = false;
					}
					j++;
					continue;
				}
				else if (check && p == 0){
						check = false;
						p = b;
						continue;
				}
			}
		}
	}
	for (int i = 1; i <= r*a; i++) {
		for (int j = 1; j <= c*b; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}
