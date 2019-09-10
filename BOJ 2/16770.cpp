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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
int main() {
	setbuf(stdout, NULL);
	vector<PP> v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int si, ti, bi;
		scanf("%d%d%d", &si, &ti, &bi);
		v.push_back({ {si,ti }, bi });
	}
	int Max = 0;
	for (int i = 1; i <= 1000; i++) {
		int temp = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[j].first.first <= i && i <= v[j].first.second) temp += v[j].second;
		}
		Max = max(Max, temp);
	}
	printf("%d\n", Max);
	return 0;
}