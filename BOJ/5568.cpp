
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
map<ll, int> m;
int n,k,check;
string s[11];
bool visited[15];
void go(int index, int cnt, int depth, string t) {
	if (cnt == depth) {
		ll ans=stoll(t);
		if (m.count(ans) == 0) {
			m[ans] = 1;
			check++;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			go(i + 1, cnt + 1, depth, t + s[i]);
			visited[i] = false;
		}
	}

}
int main() {
	scanf("%d%d", &n,&k);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	go(0, 0, k, "");
	printf("%d\n", check);
	return 0;
}