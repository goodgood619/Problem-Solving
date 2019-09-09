#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
int cow[50005];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cow[i]);
	}
	sort(cow + 1, cow + n + 1);
	int left = 0;
	int right = 1000000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		int ok = 1;
		int last = 1;
		for (int i = 2; i <= n; i++){
			if (cow[i] - cow[last] >2 * mid) {
				ok++;
				last = i;
			}
		}
		if (ok>k) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d\n", left);
	return 0;
}