#include <cstdio>
#include <algorithm>
#include <cstdint>
using namespace std;
typedef int64_t ll;
int main() {
	int n;
	scanf("%d", &n);
	int num = 666, cnt = 1;
	while (1) {
		if (cnt == n) break;
		num++;
		int temp = num;
		int six = 0;
		while (temp) {
			int sk = temp % 10;
			if (sk == 6) six++;
			else if (six < 3) six = 0;
			temp /= 10;
		}
		if (six >= 3) cnt++;
	}
	printf("%d\n", num);
	return 0;
}