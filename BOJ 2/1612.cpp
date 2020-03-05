#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 0) printf("-1");
	else {
		int k = 0;
		for (int i = 1; i <= n; i++) {
			k = (k * 10 + 1) % n;
			if (k == 0) {
				printf("%d", i);
				return 0;
			}
		}
		printf("-1");
	}
	return 0;
}