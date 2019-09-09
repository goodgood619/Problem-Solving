#include <stdio.h>
#include <algorithm>
using namespace std;
int n, k;
int q;
char board[1010][30];
char last[30];
int idx[30];
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", last);
	for (int i = 0; i<k; ++i) {
		scanf("%s", board[i]);
		if (board[i][0] == '?')q = i;
	}
	for (int i = 0; i<n; ++i) {
		idx[last[i] - 'A'] = i;
	}

	for (int i = 0; i<n - 1; ++i) {
		board[q][i] = '*'; //?엿던곳을 우선 *로 채워넣고
	}
	for (int i = 0; i<n; ++i) {
		int ux = i;
		int dx = idx[i];
		for (int x = 0; x<q; ++x) { //위에서 아래로
			if (board[x][ux] == '-') {
				ux++;
			}
			else if (ux>0 && board[x][ux - 1] == '-') {
				ux--;
			}
		}
		for (int x = k - 1; x>q; --x) { // 아래에서 위로
			if (board[x][dx] == '-') {
				dx++;
			}
			else if (dx>0 && board[x][dx - 1] == '-') {
				dx--;
			}
		}
		if (abs(ux - dx)>1) { // 차이값이 2이상이면 안되는거니까
			for (int j = 0; j<n - 1; ++j) {
				board[q][j] = 'x'; // X로 표시후 break
			}
			break;
		}
		if (ux - dx == 1) {
			board[q][dx] = '-';
		}
		else if (dx - ux == 1) {
			board[q][ux] = '-';
		}
	}
	printf("%s\n",board[q]);
	return 0;
}