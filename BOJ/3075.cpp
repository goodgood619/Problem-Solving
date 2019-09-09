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
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, p, q;
		scanf("%d%d%d", &n, &p, &q);
		ll board[105][105] = { 0, };
		int cnt[105] = { 0, };
		vector<int> v;
		int Max = 0;
		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
			cnt[num]++;
			Max = max(cnt[num], Max);
		}
		for (int i = 1; i <= p; i++) {
			for (int j = 1; j <= p; j++) {
				if(i!=j) board[i][j] = 1e14;
			}
		}
		for (int i = 1; i <= q; i++) {
			int first, second;
			ll cost;
			scanf("%d%d%lld", &first, &second, &cost);
			if (board[first][second] > cost) {
				board[first][second] = cost;
				board[second][first] = cost;
			}
		}
		if (Max == n) {
			printf("%d 0\n", v[0]);
			continue;
		}
		for (int k = 1; k <= p; k++) {
			for (int i = 1; i <= p; i++) {
				for (int j = 1; j <= p; j++) {
					if (board[i][j] > board[i][k] + board[k][j]) {
						board[i][j] = board[i][k] + board[k][j];
					}
				}
			}
		}
		ll Min = 1e14;
		ll sum = 0;
		int idx = 0;
		for (int j = 1; j <= p; j++) {
			sum = 0;
			for (int i = 0; i < v.size(); i++) {
				int here = v[i];
				if (board[here][j] == 1e14) continue;
				sum += (board[here][j] * board[here][j]);
			}
			if (Min > sum && sum != 0) {
				Min = sum;
				idx = j;
			}
		}
		printf("%d %lld\n", idx, Min);
	}
	return 0;
}