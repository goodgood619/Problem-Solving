#include <stdio.h>
#include <algorithm>
using namespace std;
int n, k,idx,cnt;
int coin[20];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &coin[i]);
	for (int i = n; k > 0; i--) {
		if (k / coin[i] == 0) continue;
		else idx = i;
		cnt += (k / coin[idx]);
		k = k%coin[idx];
		i = n;
	}
	printf("%d\n", cnt);
	return 0;
}