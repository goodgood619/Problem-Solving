#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
using namespace std;
typedef int32_t Int;
int sum[1000001];
int main() {
	Int n,k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int ice, pos;
		scanf("%d%d", &ice, &pos);
		sum[pos] = ice;
	}
	k = 2 * k+1;
	int hab = 0,ans =0 ;
	for (int i = 0; i <= 1000000; i++) {
		if (i>=k) hab -= sum[i-k];
		hab += sum[i];
		ans = max(ans, hab);
	}
	printf("%d\n", ans);
	return 0;
}