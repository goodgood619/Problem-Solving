#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int n;
string s[105];
int cnt[27];
int scnt[27];
int main() {
	scanf("%d", &n);
	for (int i = 0; i <n; i++) {
		cin >> s[i];
	}
	for (int j = 0; j < s[0].size(); j++) {
		scnt[s[0][j] - 'A']++;
	}
	int ans = 0;
	for (int i = 1; i <n; i++) {
		string next = s[i];
		int length = s[i].size();
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < length; j++) {
			cnt[s[i][j] - 'A']++;
		}
		int diff = 0;
		for (int i = 0; i < 26; i++) {
			if (scnt[i] == cnt[i]) continue;
			else diff += (abs(scnt[i] - cnt[i]));
		}
		if(diff<2 || (diff==2 && length==s[0].size())) ans++;
	}
	printf("%d\n", ans);
	return 0;
}