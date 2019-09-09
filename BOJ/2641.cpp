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
int t, Case = 1, n,m;
vector<pair<int, int>> v;
map<pair<pair<int, int>,pair<int,int>>, int> check;
int c(int tx,int ty,int startx,int starty) {
	if (check.count({ {tx,ty}, { startx, starty } }) == 0) {
		return 1;
	}
	else return 0;
}
int main() {
	scanf("%d", &n);
	int sx = 1, sy = 1;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if (num == 1) { //동
			int tx = sx, ty = sy;
			sx += gox[1], sy += goy[1];
			v.push_back({ sx,sy });
			check[{ {tx, ty}, { sx, sy }}] = 1;
			check[{ {sx, sy}, { tx,ty }}] = 1;
		}
		else if (num == 2) { //북
			int tx = sx, ty = sy;
			sx += gox[0], sy += goy[0];
			v.push_back({ sx,sy });
			check[{ {tx, ty}, { sx, sy }}] = 1;
			check[{ {sx, sy}, { tx,ty }}] = 1;
		}
		else if (num == 3) { //서
			int tx=sx,ty=sy;
			sx += gox[3], sy += goy[3];
			v.push_back({ sx,sy });
			check[{ {tx, ty}, { sx, sy }}] = 1;
			check[{ {sx, sy}, { tx,ty }}] = 1;
		}
		else{ //남
			int tx = sx, ty = sy;
			sx += gox[2], sy += goy[2];
			v.push_back({ sx,sy });
			check[{ {tx, ty}, { sx, sy }}] = 1;
			check[{ {sx, sy}, { tx,ty }}] = 1;
		}
	}
	scanf("%d", &m);
	vector<vector<int>> ans;
	for (int i = 0; i < m; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			temp.push_back(num);
		}
		int no = 0;
		for (int j = 0; j < v.size(); j++) {
			int tok = 0;
			int startx = v[j].first, starty = v[j].second;
			for (int k = 0; k < temp.size(); k++) {
				int move = temp[k];
				if (move == 1) {
					int tx = startx, ty = starty;
					startx += gox[1], starty += goy[1];
					if (c(tx, ty, startx, starty)) {
						tok = 1;
						break;
					}
				}
				else if (move == 2) {
					int tx = startx, ty = starty;
					startx += gox[0], starty += goy[0];
					if (c(tx, ty, startx, starty)) {
						tok = 1;
						break;
					}
				}
				else if (move == 3) {
					int tx = startx, ty = starty;
					startx += gox[3], starty += goy[3];
					if (c(tx, ty, startx, starty)) {
						tok = 1;
						break;
					}
				}
				else {
					int tx = startx, ty = starty;
					startx += gox[2], starty += goy[2];
					if (c(tx, ty, startx, starty)) {
						tok = 1;
						break;
					}
				}
			}
			if (tok == 0) {
				ans.push_back(temp);
				break;
			}
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
