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
#define mod 1000000009
#define lim 1000000000
typedef pair < int,int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { -1,1,0,0 };
int goy[4] = { 0,0,-1,1 };
int n, m;
int indegree[2005];
vector<vector<int>> a;
int main(void) {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 1; j <= cnt; j++) {
			int num;
			scanf("%d", &num);
			indegree[num]++;
			a[i].push_back(num);
		}
	}
	int yes = 0;
	for (int i = 1; i <= n; i++) {
		int check = 0;
		for (int j = 0; j < a[i].size(); j++) {
			if (indegree[a[i][j]] >= 2) continue;
			else {
				check = 1;
				break;
			}
		}
		if (check) continue;
		else {
			yes = 1;
			break;
		}
	}
	yes == 1 ? printf("1\n") : printf("0\n");
	return 0;
}