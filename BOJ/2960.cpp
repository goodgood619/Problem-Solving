
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
int n, k;
bool check[1005];
int main() {
	scanf("%d%d", &n, &k);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (check[i]) continue;
		for (int j = i; j <= n; j+=i) {
			if (check[j]) continue;
			else {
				check[j] = true;
				cnt++;
				if (cnt == k) {
					printf("%d\n", j);
					return 0;
				}
			}
		}
	}
	return 0;
}