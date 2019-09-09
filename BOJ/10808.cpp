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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int a, b, c;
int cnt[26];
int main() {
	char s[104] = { '\0', };
	scanf("%s", s);
	int length = strlen(s);
	for (int i = 0; i < length; i++) {
		cnt[s[i]-'a']++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", cnt[i]);
	}
	return 0;
}