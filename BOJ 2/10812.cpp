#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int arr[101] = { 0, };
	for (int i = 1; i <= n; i++) arr[i] = i;
	for (int i = 0; i < m; i++) {
		int left, mid, right;
		scanf("%d%d%d", &left, &right, &mid);
		int temp[101] = { 0, };
		for (int j = 1; j <= n; j++) temp[j] = arr[j];
		int idx = left;
		for (int j = mid; j <= right; j++) {
			arr[idx++] = temp[j];
		}
		for (int j = left; j < mid; j++) {
			arr[idx++] = temp[j];
		}
	}

	for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
	return 0;
}