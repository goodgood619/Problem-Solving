#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
long long n;
string ans[1001];
int main() {
	scanf("%lld", &n);
	ans[1] = "SK";
	ans[2] = "CY";
	ans[3] = "SK";
	ans[4] = "SK";
	if (n > 5) {
		if (n % 7 == 0 || n % 7 == 2) cout << "CY" << endl;
		else cout << "SK" << endl;
	}
	else cout << ans[n] << endl;
	return 0;
}