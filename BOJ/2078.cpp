#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m;
int left, right;
int main() {
	scanf("%d%d", &n, &m);
	int a = 1;
	int b = 1;
	while (1) {
		if (n == a && m == b) break;
		if (n < m) {
			m -= n;
			right++;
		}
		else if (n>m) {
			n -= m;
			left++;
		}
		if (n == a && m != b) {
			right += (m - 1);
			m -= (m - 1);
		}
		else if (n != a && m == b) {
			left+= (n - 1);
			n -= (n - 1);
		}
	}
	printf("%d %d\n", left, right);
	return 0;
}