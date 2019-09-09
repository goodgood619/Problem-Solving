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
typedef pair<int,int> P;
typedef pair<pair<int, int>,int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, k;
vector<double> v;
int main() {
	scanf("%d%d", &n,&k);
	for (int i = 1; i <= n; i++) {
		double num;
		scanf("%lf", &num);
		v.push_back(num);
	}
	int cnt = 1;
	sort(v.begin(), v.end());
	for (int i = 0,t=0; i < v.size(); i++) {
		if (v[i] - v[t] >= k) {
			cnt++;
			t = i;
		}
	}
	printf("%d\n", cnt);
	return 0;
}