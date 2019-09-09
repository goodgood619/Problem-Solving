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
typedef pair<int, pair<ll, char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n,same1,same2;
string s1, s2;
bool visited1[55];
bool visited2[55];
int main() {
	scanf("%d", &n);
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[i]) {
			same1++;
			visited1[i] = true;
			visited2[i] = true;
		}
	}

	for (int i = 0; i < s1.size(); i++) {
		char c = s1[i];
		if (visited1[i]) continue;
		for (int j = 0; j < s2.size(); j++) {
			if (c == s2[j] && i != j) {
				if (visited2[j]) {
					continue;
				}
				same2++;
				visited2[j] = true;
				break;
			}
		}
	}
	printf("%d %d\n", same1, same2);
	return 0;
}

