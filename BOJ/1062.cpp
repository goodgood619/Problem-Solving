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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, k,ans;
bool visited[26];
vector<char> v;
string s[55];
void go(int index,int cnt,int depth) {
	if (cnt == depth) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			int no = 0;
			for (int j = 0; j < s[i].size(); j++) {
				if (visited[s[i][j] - 'a']) continue;
				else {
					no = 1;
					break;
				}
			}
			if (!no) temp++;
		}
		ans = max(ans, temp);
		return;
	}
	for (int i = index; i < 26; i++) {
		if (!visited[i]) {
			visited[i] = true;
			go(i + 1, cnt + 1, depth);
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (k < 5) {
		printf("0\n");
	}
	else {
		k -= 5;
		visited['a' - 'a'] = true, visited['n' - 'a'] = true, visited['t' - 'a'] = true, visited['i' - 'a'] = true, visited['c' - 'a'] = true;
		go(0, 0, k);
		printf("%d\n", ans);
	}
	return 0;
}