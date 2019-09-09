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
map<vector<int>, int> m;
int n;
int arr[205][4];
int earn[205];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}

	for (int j = 1; j <= 3; j++) {
		int score[105] = { 0, };
		for (int i = 1; i <= n; i++) {
			score[arr[i][j]]++;
		}

		for (int i = 1; i <= 100; i++) {
			if (score[i] == 0 || score[i] >= 2) continue;
			else {
				for (int k = 1; k <= n; k++) {
					if (i == arr[k][j]) {
						earn[k] += i;
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", earn[i]);
	}
	return 0;
}