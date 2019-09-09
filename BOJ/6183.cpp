#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
string s[1005];
string good[105];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> good[i];
	}

	for (int i = 1; i <= n; i++) {
		string here = s[i];
		int cnt = 0;
		for (int j = 1; j <= m; j++) {
			string g = good[j];
			int idx = 0;
			for (int k = 0; k < here.size(); k++) {
				if (idx == g.size()) break;
				if (g[idx] == here[k] || g[idx]==here[k]+32 || g[idx]+32==here[k]) {
					idx++;
				}
			}
			if(idx==g.size()) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}