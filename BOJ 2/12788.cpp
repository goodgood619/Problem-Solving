#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;
typedef int64_t ll;
int main() {
	int n;
	scanf("%d", &n);
	int m, k;
	scanf("%d%d", &m, &k);
	m *= k;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr+0, arr+n);
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (m <= 0) break;
		m -= arr[i];
		cnt++;
	}
	if (m > 0 && cnt == n) printf("STRESS");
	else printf("%d\n", cnt);
	return 0;
}