#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> brand;
	brand.assign(m + 1, 0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int brandName;
		scanf("%d", &brandName);
		brand[brandName]++;
		ans = max(ans, brand[brandName]);
	}
	printf("%d\n", ans);
	brand.clear();
	return 0;
}