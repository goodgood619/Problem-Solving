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
typedef pair<int, int> P;
typedef long long ll;
ll n;
int temp[64];
int maxtemp[64];
int mintemp[64];
int real,length;
int main(){
	scanf("%lld", &n);
	ll p = n;
	for (int i = 63; i >= 0; i--) {
		temp[i] = n % 2;
		mintemp[i] = n % 2;
		maxtemp[i] = n % 2;
		n /= 2;
	}
	next_permutation(maxtemp,maxtemp + 64);
	ll Max = 0;
	for (int i = 0; i < 64; i++) {
		Max +=(ll)(maxtemp[i] * pow(2, 63 - i));
	}
	if (!prev_permutation(mintemp,mintemp + 64)) {
		printf("0 ");
	}
	else {
		ll Min = 0;
		for (int i = 0; i < 64; i++) {
			Min += (ll)(mintemp[i] * pow(2, 63 - i));
		}
		printf("%lld ", Min);
	}
	printf("%lld\n", Max);
	return 0;
}