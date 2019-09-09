#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int n, k;
int h = 1;
int arr[50005];
vector<int> seg;
map<int, int> m;
void update(int index, int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
	}
}
int query(int nodenum, int nodeleft, int noderight, int left, int right) {
	if (nodeleft > right || noderight < left) return 0;
	else if (left <= nodeleft && noderight <= right) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return max(query(nodenum * 2, nodeleft, mid, left, right), query(nodenum * 2 + 1, mid + 1, noderight, left, right));
}
int main() {
	scanf("%d%d", &n, &k);
	while (h < n)h *= 2;
	seg.resize(2 * h);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		m[arr[i]]++;
	}
	sort(arr + 1, arr + n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int *idx = lower_bound(arr + 1, arr + n + 1, arr[i] + k);
		int *idx2 = upper_bound(arr + 1, arr + n + 1, arr[i] + k);
		if (m.count(arr[i] + k) != 0) {
			cnt = idx2 - (arr + i);
		}
		else
		cnt = idx-(arr+i);
		update(i, cnt);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int here1 = seg[h + i - 1];
		int here2 = query(1, 1, h, i + here1, h);
		ans = max(ans, here1 + here2);
	}
	printf("%d\n", ans);
	return 0;
}