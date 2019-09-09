#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
vector<int> seg;
int n, h = 1;
typedef pair<int, int> P;
P anspo[100005];
void update(int index, int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
int query(int nodenum, int L, int R, int nodeleft, int noderight) {
	if (nodeleft > R || noderight < L) return 0;
	else if (L <= nodeleft && noderight<=R) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return query(nodenum * 2, L, R, nodeleft, mid) + query(nodenum * 2 + 1, L, R, mid + 1, noderight);
}

int main(){
	scanf("%d", &n);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		anspo[i].first = num;
		anspo[i].second = i;
	}
	sort(anspo + 1, anspo + n + 1);
	for (int i = 1; i <= n; i++) {
		update(i, 1);
	}
	int total = n;
	int leftptr = 1;
	int rightptr = n;
	bool check = false;
	for (;leftptr<=rightptr;){
		if (!check) {
			int what = anspo[leftptr].second;
			int ans = query(1,1,what, 1, h) - 1;
			printf("%d\n", ans);
			update(what, 0);
			leftptr++;
			check = true;
		}
		else{
			int what = anspo[rightptr].second;
			int ans = query(1, what, h, 1, h) - 1;
			printf("%d\n", ans);
			update(what, 0);
			rightptr--;
			check =false;

		}
	}
	return 0;
}