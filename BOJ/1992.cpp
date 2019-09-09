#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
int n;
int board[70][70];
string s;
void go(int x, int y, int depth){
	int check[2] = { 0, };
	for (int i = x; i <x+depth; i++) {
		for (int j = y; j <y+depth; j++) {
			if (board[i][j] ==0) {
				check[0]++;
			}
			else {
				check[1]++;
			}
		}
	}
	if (check[0] == depth*depth) {
		s.push_back('0');
		return;
	}
	else if(check[1] == depth*depth) {
		s.push_back('1');
		return;
	}
	else {
		s.push_back('(');
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				go(x + i*(depth / 2), y +j*(depth / 2), depth / 2);
			}
		}
		s.push_back(')');
	}

}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	go(1, 1, n);
	printf("%s\n", s.c_str());
	return 0;
}