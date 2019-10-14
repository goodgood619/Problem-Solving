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
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
struct pos {
	int r;
	int c;
	int s;
};
void Rotate(vector<pos> &v,int **board,int n,int m,int &ans) {
	int **tempboard = new int*[n];
	for (int i = 0; i < n; i++) tempboard[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tempboard[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].r, y = v[i].c, s = v[i].s;
		while (s > 0) {
			int temp = tempboard[x - s][y - s];
			for (int i = x - s; i < x + s; i++) tempboard[i][y-s] = tempboard[i + 1][y - s];
			for (int j = y - s; j < y + s; j++) tempboard[x+s][j] = tempboard[x+s][j+1];
			for (int i = x + s; i > x - s; i--) tempboard[i][y+s] = tempboard[i-1][y+s];
			for (int j = y + s; j > y - s + 1; j--) tempboard[x-s][j] = tempboard[x-s][j-1];
			tempboard[x - s][y - s + 1] = temp;
			s--;
		}
	}

	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < m; j++) {
			temp += tempboard[i][j];
		}
		ans = min(ans, temp);
	}
	for (int i = 0; i < n; i++) delete[] tempboard[i];
	delete[] tempboard;
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int **board = new int*[n];
	for (int i = 0; i < n; i++)board[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d",&board[i][j]);
		}
	}
	int ans = 1e9;
	vector<pos> v;
	for (int i = 0; i < k; i++) {
		int r, c, s;
		scanf("%d%d%d", &r, &c, &s);
		r--, c--;
		v.push_back({ r,c,s });
	}
	vector<int> temp;
	for (int i = 0; i < k; i++) temp.push_back(i);
	do {
		vector<int> order;
		for (int i = 0; i < temp.size(); i++) {
			order.push_back(temp[i]);
		}
		vector<pos> realorder;
		for (int i = 0; i < order.size(); i++) {
			realorder.push_back(v[order[i]]);
		}
		Rotate(realorder,board,n,m,ans);
	} while (next_permutation(temp.begin(), temp.end()));
	printf("%d\n", ans);
	for (int i = 0; i < n; i++) delete[] board[i];
	delete[] board;
	return 0;
}