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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int dp[2005][2005];
int solution(vector<int> cookie) {
	int answer = -1;
	for (int i = 0; i < cookie.size(); i++) {
		for (int j = i; j < cookie.size(); j++) {
			dp[i + 1][j + 1] += dp[i + 1][j] + cookie[j];
		}
	}

	for (int i = 0; i < cookie.size(); i++) {
		for (int j = i+1; j < cookie.size(); j++) {
			int left = i + 1;
			int right = j + 1;
			while (left <=right) {
				int mid = (left + right) / 2;
				if (dp[i+1][mid] == dp[mid + 1][j+1]) {
					answer = max(answer, dp[i+1][mid]);
                    break;
				}
             
				if (dp[i+1][mid] > dp[mid + 1][j+1]) right=mid-1;
				else left=mid+1;
			}
		}
	}
	if (answer == -1) answer = 0;
	return answer;
}