
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
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int t;
int isprime[10005];
map<int, int> m;
int main() {
	for (int i = 2; i <= 10000; i++) isprime[i] = i;
	for (int i = 2; i <= sqrt(10000); i++) {
		if (isprime[i] == 0) continue;
		for (int j = i*i; j <= 10000; j += i) {
			isprime[j] = 0;
		}
	}
	scanf("%d", &t);
	while (t--) {
		int Case, n;
		int check = 0;
		scanf("%d%d", &Case, &n);
		m.clear();
		if (n == 1) {
			printf("%d %d NO\n", Case, n);
			continue;
		}
		int temp = n;
		while (1) {
			int sum = 0;
			while (temp > 0) {
				sum += (temp % 10)*(temp%10);
				temp /= 10;
			}
			if (sum == 1) {
				check = 1;
				break;
			}
			if (m.count(sum) == 0) {
				m[sum] = 1;
			}
			else if (m.count(sum) != 0) {
				break;
			}
			temp = sum;
		}
		if(isprime[n]!=0 && check) printf("%d %d YES\n", Case, n);
		else printf("%d %d NO\n", Case, n);
	}
	return 0;
}