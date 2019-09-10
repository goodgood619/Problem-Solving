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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
vector<pair<string, char>> v;
int main() {
	setbuf(stdout, NULL);
	int n, p,w,l,g;
	cin >> n >> p >> w >> l >> g;
	for (int i = 1; i <= p; i++) {
		string s;
		char c;
		cin >> s >> c;
		v.push_back({ s,c });
	}
	int sum = 0,ok=0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int check = 0;
		for (int j = 0; j < v.size(); j++) {
			if (s == v[j].first) {
				if (v[j].second == 'W') sum += w;
				else sum -= l;
				if (sum < 0) sum = 0;
				check = 1;
				break;
			}
		}
		if (!check) {
			sum -= l;
			if (sum < 0) sum = 0;
		}
		if (sum >= g) {
			ok = 1;
		}
	}
	ok == 1 ? printf("I AM NOT IRONMAN!!") : printf("I AM IRONMAN!!");
	return 0;
}