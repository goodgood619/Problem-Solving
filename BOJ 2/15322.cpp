#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", min(2 * (n - 1), 2 * (m - 1)));
	}
	return 0;
}