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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
string s[13];
int cnt[27];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		string here = s[i];
		for (int j = 0; j < here.size(); j++) {
			cnt[here[j] - 'A'] += pow(10, here.size() - j - 1);
		}
	}
	sort(cnt, cnt + 27);
	ll sum = 0;
	int num = 9;
	for (int i = 26; cnt[i] != 0; i--) {
		sum += (ll)cnt[i] * num;
		num--;
	}
	printf("%lld\n", sum);
	return 0;
}