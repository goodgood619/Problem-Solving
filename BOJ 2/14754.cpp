#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <math.h>
using namespace std;
typedef long long ll;
vector<ll> p;
vector<ll> q;
int n, m;
int board[1005][1005];
int side[1005];
int front[1005];
int main(){
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int i = 1; i <= n; i++){
		int sideMax = 0;
		for (int j = 1; j <= m; j++) {
			sideMax = max(sideMax, board[i][j]);
		}
		side[i] = sideMax;
	}
	for (int j = 1; j <= m; j++) {
		int frontMax = 0;
		for (int i = 1; i <=n; i++) {
			frontMax = max(frontMax, board[i][j]);
		}
		front[j] = frontMax;
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			if (side[i] == board[i][j]) {
				continue;
			}
			else if (side[i] != board[i][j]) {
				if (front[j] == board[i][j]) continue;
				else sum += board[i][j];
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}