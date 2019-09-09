#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits>
#include <math.h>
#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
ll r, b,Max1,Max2;
bool ok;
int main(){
	scanf("%lld%lld", &r, &b);
	for (ll i = 1; i <= sqrt(b); i++){
		if (b%i == 0) {
			ll temp = b / i;
			ll temp2 = 2 * (temp + i) + 4;
			if (temp2 == r){
				ok = true;
				Max1 = max(temp+ 2, i + 2);
				Max2 = min(temp+ 2, i + 2);
				break;
			}
		}
		if (ok) break;	
	}
	printf("%lld %lld", Max1, Max2);
	return 0;
}