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
int t, Case = 1, n,m,k,cnt;
int main() {
	scanf("%d%d%d", &m, &n,&k);
	vector<int> v1, v2;
	v1.push_back(0), v2.push_back(0);
	for (int i = 0; i < k; i++) {
		int what,a;
		scanf("%d", &what);
		if (what == 0) { //가로로자르기
			scanf("%d", &a);
			v1.push_back(a);
		}
		else {//세로로 자르기
			scanf("%d", &a);
			v2.push_back(a);
		}
	}
	v1.push_back(n),v2.push_back(m);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int height = 0, width = 0;
	for (int i = 0; i < v1.size() - 1; i++) {
		height = max(height, v1[i + 1] - v1[i]);
	}
	for (int i = 0; i < v2.size() - 1; i++) {
		width = max(width, v2[i + 1] - v2[i]);
	}
	printf("%d\n", height*width);
	return 0;
}