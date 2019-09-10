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
using namespace std;
typedef long long ll;
int dp[100][100];
int board[100][100];
int n;
bool ok;
int go(int a, int b){
	if (a > n || b > n) return 0;
	else if (a == n && b == n) {
		ok = true;
		return 1;
	}
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	ret = 1;
	int jump = board[a][b];
	ret = max(go(a + jump,b), go(a, b + jump));
	return ret;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	int ok2 = go(1, 1);
	if (ok) printf("HaruHaru\n");
	else printf("Hing\n");
	return 0;
}