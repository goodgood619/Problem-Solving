#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,path;
char board[6][6];
bool visited[6][6];
vector<string> v;
int go(int x,int y,string s,int cnt) {
	//if (cnt > path && path!=0) return 0;
	if (x == n && y == n) {
		//if (path == 0) path = cnt;
		v.push_back(s);
		return 0;
	}
	//visited[x][y] = true;
	for (int i = 0; i < 2; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>n ) continue;
		go(nx, ny, s + board[nx][ny], cnt + 1);
	}
	//visited[x][y] = false;
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	go(1, 1, "",1);
	int Min = 1e9, Max = -1e9;
	for (int i = 0; i < v.size(); i++) {
		int temp = board[1][1] - '0';
		for (int j = 0; j < v[i].size(); j+=2) {
			if (v[i][j] == '+') temp += (v[i][j + 1] - '0');
			else if (v[i][j] == '-') temp -= (v[i][j + 1] - '0');
			else if (v[i][j] == '*') temp *= (v[i][j + 1] - '0');
		}
		Min = min(Min, temp), Max = max(Max, temp);
	}
	printf("%d %d\n", Max, Min);
	return 0;
}