
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
bool check[1000005];
int main() {
	check[1] = true;
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (check[i]) continue;
		for (int j = i*i; j <= 1000000; j += i) {
				check[j] = true;
		}
	}
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = n - 1; i >= 1; i--) {
			if (!check[i] && !check[n-i]) {
				printf("%d = %d + %d\n", n,n-i,i);
				break;
			}
		}
	}
	return 0;
}