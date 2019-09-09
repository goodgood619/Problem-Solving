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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
P arr[505];
int dp[505][505];
int main() {
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			dp[i][j] = 1e9;
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		arr[i].first = left;
		arr[i].second = right;
	}

	for (int i = 1; i <= n; i++) dp[i][i] = 0;

	//한번가면서 다 구해놓기는 해야함

	for (int k = 1; k <= n; k++) { //맨바깥은 차이가 1부터 늘리기
		for (int i = 1; i <= n-k; i++) { //i는 시작
			int j = i + k;//여기서 k라는 차이를 알수있으니까, 목적지인 j를 지정할수있다
			if (i == j) continue;
			for (int p = i; p < j; p++) { // 
				dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j] + arr[i].first * arr[p+1].first * arr[j].second);
			}

		}
	}
	printf("%d\n", dp[1][n]);
	return 0;

}