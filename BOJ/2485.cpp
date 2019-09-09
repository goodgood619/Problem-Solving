#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
using namespace std;
int n, m, cnt;
typedef pair<int, int> P;
typedef long long ll;
ll arr[100005];
ll diff[100005];
ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%lld", &arr[i]);
	sort(arr + 1, arr + n + 1);
	ll Min = 1e11;
	for (int i = 1; i < n; i++) {
		diff[i] = arr[i + 1] - arr[i];
		Min = min(Min, diff[i]);
	}
	ll cnt = 0;
	Min = gcd(diff[1], diff[2]);
	for (int i = 3; i < n; i++) {
		Min=gcd(Min, diff[i]);
	}
	for (int i = 1; i < n; i++) {
		cnt += ((diff[i] / Min) - 1);
	}
	printf("%lld\n", cnt);
	return 0;
}