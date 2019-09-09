#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char board[505];
int ok[505];
int real[505];
int k,dotcnt;
int main(){
	scanf("%s", board);
	int length = strlen(board);
	int cnt = 0;
	for (int i = 0; i < length; i++) {
		char c = board[i];
		if (c == 'X') {
			cnt++;
		}
		else if (c == '.'){
			ok[i] = cnt;
			real[i] = cnt;
			cnt = 0;
			dotcnt++;
		}
	}
	ok[length] = cnt;
	real[length] = cnt;
	bool check = false;
	for (int i = 0; i <=length; i++) {
		if (ok[i] % 2 == 0 || ok[i]==0) continue;
		else {
			check = true;
			break;
		}

	}
	if (check) printf("-1\n");
	else if (dotcnt == length) {
		printf("%s\n", board);
	}
	else {
		for (int i = 0; i <=length; i++) {
			if (ok[i] == 0) continue;
			else if (ok[i] % 4 != 0) {
				if (ok[i] > 2) {
					int whatcnt = ok[i];
					board[i - 1] = 'B';
					board[i - 2] = 'B';
					whatcnt -= 2;
					int p = i - 2;
					for (int j =p-1; whatcnt != 0; j--) {
						board[j] = 'A';
						whatcnt--;
					}
				}
				else{
					int whatcnt = ok[i];
					for (int j = i - 1; whatcnt != 0; j--) {
						board[j] = 'B';
						whatcnt--;
					}
				}
			}
			else if (ok[i] % 4 == 0) {
				int whatcnt = ok[i];
				for (int j = i - 1; whatcnt != 0; j--) {
					board[j] = 'A';
					whatcnt--;
				}
			}
		}
		printf("%s\n", board);
	}
	return 0;
}