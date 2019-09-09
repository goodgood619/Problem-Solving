#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
ll arr[66];
int main() {
	int n;
	scanf("%d", &n);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			arr[i] = arr[i - 1] * 2 + 1;
		}
		else {
			arr[i] = arr[i - 1] * 2 - 1;
		}
	}
	printf("%lld\n", arr[n]);
 	return 0;
}