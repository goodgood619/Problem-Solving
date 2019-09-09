#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int n;
typedef long long ll;
int main(){
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int length = s.size();
		ll temp = 0;
		for (int i = 0; i < length - 1; i++) {
			temp += (s[i] - '0')*pow(10, length - 2 - i);
		}
		int gob = s[length - 1] - '0';
		if (gob == 0) temp = 1;
		ll p = temp;
		for (int i = 1; i <gob; i++) {
			temp *=p;
		}
		sum += temp;
	}
	printf("%lld\n", sum);
	return 0;
}

