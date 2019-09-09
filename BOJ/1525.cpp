#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int board[4][4];
int sx, sy;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
map<int, int> cnt;
void bfs(int x, int y,string s){
	int start = stoi(s);
	cnt[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int num = q.front();
		string snum = to_string(num);
		q.pop();
		int z = snum.find('9');
		int x = z / 3;
		int y = z % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
			else {
				string next = snum;
				swap(next[x * 3 + y], next[nx * 3 + ny]);
				int nextnum = stoi(next);
				if (cnt.count(nextnum) == 0) {
					cnt[nextnum] = cnt[num] + 1;
					q.push(nextnum);
				}
			}
		}
	}
}
int main(){
	string num;
	for (int i = 0; i <3; i++) {
		for (int j = 0; j <3; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] ==0) {
				board[i][j] =9;
			}
			num.push_back(board[i][j] + '0');
		}
	}
	bfs(sx, sy,num);
	if (cnt.count(123456789) == 0) printf("-1\n");
	else printf("%d\n", cnt[123456789]);
	return 0;
}