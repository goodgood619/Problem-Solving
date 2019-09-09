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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1, n, m;
int main() {
	while (true) {
		int num;
		scanf("%d", &num);
		if (num == 0) break;
		string s = to_string(num);
		int no = 0;
		for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
			if (s[i] != s[j]) {
				no = 1;
				break;
			}
		}
		no ? printf("no\n") : printf("yes\n");
	}
	return 0;
}