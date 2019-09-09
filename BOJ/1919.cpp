
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
string s1, s2;
int a[26];
int b[26];
int main() {
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		a[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.size(); i++) {
		b[s2[i] - 'a']++;
	}
	int sum = 0;
	for (int i = 0; i < 26; i++) {
		sum += max(a[i], b[i]) - min(a[i], b[i]);
	}
	printf("%d\n", sum);
	return 0;
}