#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int a,b;
int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		int g = gcd(a, b);
		printf("%d %d\n",a / g*b / g*g,g);
	}
	return 0;
}