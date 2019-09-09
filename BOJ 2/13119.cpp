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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<ll, int> P;
typedef pair<int, pair<int, ll>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, x;
int height[200005];
int c;
vector<vector<char>> v;
int main(){
	scanf("%d%d%d", &n, &m, &x);
	v.resize(n + 1);
	for (int i = 1; i <= m; i++) { scanf("%d", &height[i]);}
	for (int i = n; i>=1; i--){
		c++;
		for (int j = 1; j <= m; j++){
			int cnt = height[j];
			if (c== x) {
				if (cnt > 0) {
					v[i].push_back('*');
					height[j]--;
				}
				else v[i].push_back('-');
			}
			else{
				if (j % 3 == 0 && c<x) {
					if (cnt <= 0) {
						v[i].push_back('|');

					}
					else {
						v[i].push_back('#');
						height[j]--;
					}
				}
				else {
					if (cnt <= 0) {
						v[i].push_back('.');
					}
					else {
						v[i].push_back('#');
						height[j]--;
					}
				}
			}
		}
	}
	for (int i = 1; i<=n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			printf("%c", v[i][j]);
		}
		printf("\n");
	}
	return 0;
}