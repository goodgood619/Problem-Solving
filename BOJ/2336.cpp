#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
int n;
#define INF 99999999
typedef pair<int, pair<int, int>> P;
P anspo[500005];
vector<int> seg;
int h = 1;
void update(int index, int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = min(seg[index * 2], seg[index * 2 + 1]);
	}
}
int query(int nodenum, int L, int R, int nodeleft, int noderight) {
	if (nodeleft > R || noderight < L) return INF;
	else if (L <= nodeleft && noderight <= R) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return min(query(nodenum * 2, L, R, nodeleft, mid), query(nodenum * 2 + 1, L, R, mid + 1, noderight));
}
int main() {
	scanf("%d", &n);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <seg.size(); i++) {
		seg[i] = INF;
	}
	for (int i = 1; i <= 3; i++) {
		if (i == 1) {
			for (int j = 1; j <= n; j++) {
				int num;
				scanf("%d", &num);
				anspo[num].first = j;
			}
		}
		else if (i == 2) {
			for (int j = 1; j <= n; j++) {
				int num;
				scanf("%d", &num);
				anspo[num].second.first = j;
			}
		}
		else if (i == 3) {
			for (int j = 1; j <= n; j++) {
				int num;
				scanf("%d", &num);
				anspo[num].second.second = j;
			}
		}
	}
	sort(anspo + 1, anspo + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int left = anspo[i].second.first;
		int thirdleft = anspo[i].second.second;
		int thirdquery = query(1, 1,left-1, 1, h);
		if (thirdleft < thirdquery) ans++;
		update(left,thirdleft);
	}
	printf("%d\n", ans);
	return 0;
}