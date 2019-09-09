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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
ll dp[2][10005];
int step[10005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &step[i]);
	}
	if (step[1] > 0) {
		printf("0\n");
		return 0;
	}
	else {
		if (step[1] == -1) dp[0][0] = 1; //왜냐하면, 첫번째제단의 높이는 무조건 0이어야하므로
		else if (step[1] == 0) dp[0][0] = 1;

		for (int i = 2; i <= n; i++) {
			if (step[i] == -1) { //step을 모른다(모든 높이에 대해서 갱신을 시켜줘야한다)
				dp[1][0] = dp[0][0] + dp[0][1];
				for (int j = 1; j <= n / 2; j++) {
					dp[1][j] = (dp[0][j - 1] + dp[0][j] + dp[0][j + 1])%mod;
				}
			}
			else if (step[i] == 0) { // 높이가 0이다
				dp[1][0] = (dp[0][0] + dp[0][1])%mod;
			}
			else { //높이가 0이 아니다
				dp[1][step[i]] = (dp[0][step[i] - 1] + dp[0][step[i]] + dp[0][step[i] + 1])%mod;
			}

			for (int k = 0; k <= n / 2; k++) { //이전정보를 옮겨준다
				dp[0][k] = dp[1][k]; //옮기고
				dp[1][k] = 0;
			}
		}
		printf("%lld\n", dp[0][0] % mod);

	}

	return 0;

}