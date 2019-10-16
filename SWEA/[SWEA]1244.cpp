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
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int Case = 1;
string s;
int k,ans;
void go(int index,int cnt,int depth) {
	if (cnt == depth) {
		ans = max(ans, stoi(s));
		return;
	}
	for (int i = index; i < s.size(); i++) {
		for (int j = i+1; j < s.size(); j++) {
			if (s[i] <= s[j]) {
				swap(s[i], s[j]);
				go(i, cnt + 1, depth);
				swap(s[i], s[j]);
			}
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> s >> k;
		ans = 0;
		go(0, 0,k);
		printf("#%d %d\n", Case++, ans);
	}
	return 0;
}