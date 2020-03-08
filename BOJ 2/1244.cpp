#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int arr[101] = { 0, };
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int st, pos;
		scanf("%d%d", &st, &pos);
		if (st == 1) {
			for (int j = pos; j <= n; j += pos) {
				arr[j] == 0 ? arr[j] = 1 : arr[j] = 0;
			}
		}
		else {
			int start = 0, end = 0;
			for (int j = pos, left = pos - 1, right = pos + 1; left >= 1 && right <= n; left--, right++) {
				if (arr[left] == arr[right]) {
					start = left;
					end = right;
				}
				else break;
			}
			if (start == 0) arr[pos] == 0 ? arr[pos] = 1 : arr[pos] = 0;
			for (int j = start; j <= end; j++) {
				arr[j] == 0 ? arr[j] = 1 : arr[j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
		if (i % 20 == 0) printf("\n");
	}
	return 0;
}