#include <stdio.h>
#include <algorithm>
using namespace std;
long long hab,n;
int main() {
	scanf("%lld", &n);
	for (long long i = 1; i < n; i++) {
		hab = hab + ((n*i) + i);
	}
	printf("%lld\n", hab);
	return 0;
}