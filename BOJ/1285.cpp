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
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,1,-1,1,-1 };
int n, result = INF;
bool coin[20][20], r[20];

void dfs(int pos) {
	if (pos == n) {
		int sum = 0;
		for (int c = 0; c<n; c++) {
			int cnt = 0;
			for (int k = 0; k<n; k++)
				if (coin[k][c] != r[k]) cnt++;
			sum += min(cnt, n - cnt);
		}
		result = min(result, sum);
		return;
	}
	dfs(pos + 1);
	r[pos] = true;
	dfs(pos + 1);
	r[pos] = false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			scanf(" %c", &c);
			coin[i][j] = (c == 'T');
		}
	}
	dfs(0);
	printf("%d\n", result);
}