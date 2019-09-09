#include <cstdio>
#include <algorithm>
using namespace std;
int rope[100004];
int n,Max;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &rope[i]); }
	sort(rope + 1, rope + n + 1);
	for (int i = 1; i <= n; i++) {
		Max=max(rope[i] * (n - i + 1), Max);
	}
	printf("%d\n", Max);
	return 0;
}