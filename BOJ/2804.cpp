#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int idx, idy;
char a[31];
char b[31];
char board[40][40];
bool check;
int main() {
	scanf("%s%s", a, b);
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j <40; j++) {
			board[i][j] = '.';
		}
	}
	int length1 = strlen(a);
	int length2 = strlen(b);
	for (int i = 0; i <length1; i++) {
		for (int j = 0; j <length2; j++) {
			if (a[i] == b[j]) {
				idx = i;
				idy = j;
				check = true;
				break;
			}
		}
		if (check)break;

	}
	for (int i = 0; i < length2; i++) {
		board[i][idx] = b[i];
	}
	for (int j = 0; j < length1; j++) {
		board[idy][j] = a[j];
	}
	for (int i = 0; i < length2; i++) {
		for (int j = 0; j <length1; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}