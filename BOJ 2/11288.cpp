#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
ll n, a, b;
string s;
char alpha[200];
int main() {
	scanf("%lld%lld%lld ", &n, &a, &b);
	ll p = a;
	ll mod = 26;
	if (a != 0){
		if (b == 1) p %= mod;
		for (int i = 2; i <= b; i++) {
			p *= a;
			p %= mod;
		}
	}
	if (a != 0 && b == 0) p = 1;
	if (a == 0) p = 0;
	for (int i = 65; i <91; i++) {
		alpha[i] = i;
	}

	for (int i = 0; i <n; i++) {
		char c;
		scanf("%c", &c);
		if (c == ' ') printf(" ");
		else {
			ll temp = c;
			int cd = (int)(temp + 26 - p);
			if (cd >= 65 + 26) cd -= 26;
			printf("%c", alpha[cd]);
		}
	}
	printf("\n");
	return 0;
}
