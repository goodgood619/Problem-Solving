
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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
bool isprime[1000001];
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &t);
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (isprime[i]) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			isprime[j] = true;
		}
	}
	vector<int> v;
	for (int i = 2; i <= 1000000; i++) {
		if (!isprime[i]) v.push_back(i);
	}
	while (t--) {
		ll n;
		scanf("%lld", &n);
		int no = 0;
		for (int i = 0; i < v.size(); i++) {
			if (n%v[i] == 0) {
				no = 1;
				break;
			}
		}
		no == 1 ? printf("NO\n") : printf("YES\n");
	}
	return 0;
}
