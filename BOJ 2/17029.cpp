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
int t, Case = 1;
int main() {
	setbuf(stdout, NULL);
	int n;
	scanf("%d", &n);
	vector<vector<string>> v;
	map<string, int> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		string s;
		int k;
		cin >> s>>k;
		for (int j = 0; j < k; j++) {
			string temp;
			cin >> temp;
			m[temp]++;
			v[i].push_back(temp);
		}
	}
	int Max = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int cnt = 0;
			for (int k = 0; k < v[i].size(); k++) {
				for (int p = 0; p < v[j].size(); p++) {
					if (v[i][k] == v[j][p]) cnt++;
				}
			}
			Max = max(Max, cnt);
		}
	}
	printf("%d\n", Max + 1);
	return 0;
}
