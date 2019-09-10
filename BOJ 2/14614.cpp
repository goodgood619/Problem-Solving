#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
long long a, b;
char s[101];
long long ans1;
int ans;
int main() {
	scanf("%lld%lld%s", &a, &b, &s);
	int c = s[strlen(s) - 1] - '0';
	if (c % 2 == 0)
		ans1 = a;
	else
		ans1 = a^b;
	printf("%lld\n", ans1);
}