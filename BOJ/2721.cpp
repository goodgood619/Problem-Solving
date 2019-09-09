#include <stdio.h>
#include <algorithm>
using namespace std;
int t,n,sum;
long long total;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i + 1; j++) {
				sum += j;
			}
			total += (i*sum);
			sum = 0;
		}
		printf("%lld\n", total);
		total = 0;
	}
	return 0;
}