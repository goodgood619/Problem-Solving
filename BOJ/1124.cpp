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
typedef pair<pair<int, int>, pair<int, bool>> PPP;
int a, b, ans;
int isprime[100005];
int underprime[100005];
int main() {
	for (int i = 2; i <= 100000; i++)isprime[i] = i;
	for (int i = 2; i <= 100000; i++) {
		for (int j = 2; j*j <= i;j++) {
			if (i%j == 0) {
				underprime[i] = underprime[i / j] + 1;
				isprime[i] = 0;
				break;
			}
		}
		if (isprime[i]) underprime[i] = 1;
	}
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++) {
		if (isprime[i] != 0) {
			continue;
		}
		else {
			int p = i;
			int mod = 2;
			int cnt = 0;
			while (p > 1) {
				if (p%mod == 0) {
					p /= mod;
					cnt++;
					break;
				}
				else mod++;
			}
			underprime[i] = underprime[i / mod] + 1;
			if (isprime[underprime[i]] != 0) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

