#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits>
#include <math.h>
#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
string s;
int ans, cnt;
bool visited[13];
int main() {
	cin >> s;
	int left = -1;
	int right = 1;
	bool no = false;
	sort(s.begin(), s.end());
	do {
		left = -1;
		right = 1;
		no = false;
		for (int i = 0; i < s.size(); i++) {
			if (i == 0) {
				if (s[i] == s[i + right]) {
					no = true;
					break;
				}
			}
			else if (i == s.size() - 1) {
				if (s[i] == s[i + left]) {
					no = true;
					break;
				}
			}
			else {
				if (s[i] == s[i + left] || s[i] == s[i + right]) {
					no = true;
					break;
				}
			}
		}
		if (!no) {
			ans++;
		}
	} while (next_permutation(s.begin(), s.end()));
	printf("%d\n", ans);
	return 0;
}