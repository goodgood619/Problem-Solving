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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1, n, m;
int main() {
	//setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	for (int i = 1; i <= 80300; i++) {
		if (i % 3 == 0 && i % 7 != 0) v.push_back(i);
		if (i % 7 == 0 && i % 3 != 0) v.push_back(i);
		if (i % 3 == 0 && i % 7 == 0) v.push_back(i);
	}
	ll sum[80001] = { 0, };
	sum[3] = 3;
	int idx = 1;
	for (int i = 3; i <= 80000; i++) {
		if (v[idx] == i) {
			sum[i] += sum[v[idx - 1]];
			sum[i] += i;
			idx++;
		}
		else sum[i] = sum[v[idx - 1]];
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout<<sum[n]<<"\n";
	}
	return 0;
}