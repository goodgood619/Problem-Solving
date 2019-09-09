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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int n;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<int> v;
int main() {
	scanf("%d", &n);
	int p = n;
	while (n > 0) {
		v.push_back(n % 10);
		n /= 10;
	}
	reverse(v.begin(), v.end());
	int ok = 0;
	if (p<= 9) {
		printf("NO\n");
		return 0;
	}
	for (int k = 0; k < v.size(); k++) {
		int left = 1;
		int right = 1;
		for (int i = 0; i <= k; i++) {
			left *= v[i];
		}
		for (int j = k + 1; j < v.size(); j++) {
			right *= v[j];
		}
		if (left == right) ok = 1;
	}
	if (ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}