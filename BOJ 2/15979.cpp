#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int a, b;
int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}
int main() {
	scanf("%d%d", &a, &b);
	if (a == 0 && b == 0) printf("0\n");
	else {
		if (a!=0 && b != 0){
			int c = gcd(abs(a), abs(b));
			if (c == 1) printf("1\n");
			else printf("2\n");
		}
		else if (b == 0 && a!=0 || a==0 && b!=0){
			if (abs(a - b) <= 1) printf("1\n");
			else printf("2\n");
		}
	}
	return 0;
}
