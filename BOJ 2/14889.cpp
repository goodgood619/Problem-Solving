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
int t, Case = 1,n,Min=1e9;
int board[20][20];
bool visited[20];
void dfs(int index,int a,int cnt) {
	if (a == cnt) {
		vector<int> temp, temp2;
		for (int i = 0; i < n; i++) {
			if (visited[i]) temp.push_back(i);
			else temp2.push_back(i);
		}
		int sum = 0, sum2 = 0;
		for (int i = 0; i < temp.size(); i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				int here = temp[i], next = temp[j];
				sum += board[here][next],sum+=board[next][here];

			}
		}
		for (int i = 0; i < temp2.size(); i++) {
			for (int j = i + 1; j < temp2.size(); j++) {
				int here = temp2[i], next = temp2[j];
				sum2 += board[here][next], sum2 += board[next][here];

			}
		}
		Min = min(Min, abs(sum - sum2));
		return;
	}
	for (int i = index; i <n ; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i + 1, a + 1, cnt);
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	dfs(0, 0,n / 2);
	printf("%d\n", Min);
	return 0;
}