#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <cstring>
using namespace std;
typedef int64_t ll;
int main() {
	int n;
	scanf("%d", &n);
	int fivecnt = 0, p = n;
	while (p > 0) {
		fivecnt += p / 5;
		p /= 5;
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int temp = i;
		while (temp % 5 == 0) temp /= 5;
		if (fivecnt > 0 && temp % 2 == 0) {
			fivecnt--;
			temp /= 2;
		}
		ans = (ans * temp) % 10;
	}
	printf("%d\n", ans);
	return 0;
}