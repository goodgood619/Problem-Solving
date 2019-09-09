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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n;
int main() {
	scanf("%d", &n);
	string s;
	cin >> s;
	string temp;
	ll sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp.push_back(s[i]);
		}
		else {
			if (!temp.empty() && temp.size() <= 6) {
				int num = stoi(temp);
				sum += (ll)num;
			}
			temp.clear();
		}
	}
	if (!temp.empty() && temp.size() <= 6) {
		int num = stoi(temp);
		sum += (ll)num;
	}
	printf("%lld\n", sum);
	return 0;
}