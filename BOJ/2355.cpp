#include <stdio.h>
#include <algorithm>
using namespace std;
long long a, b;
long long hab1,hab2;
int main() {
	scanf("%lld%lld", &a, &b);
	if (a > b) {
		long long temp = a;
		a = b;
		b = temp;
	}
	hab1 = (b*(b + 1)) / 2;
	hab2 = ((a - 1)*a) / 2;
	printf("%lld\n", hab1 - hab2);
	return 0;
}