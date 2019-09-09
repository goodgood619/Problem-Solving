#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n;
typedef pair<int, int> P;
typedef long long ll;
P anspo[1000005];
vector<ll> seg;
ll Max;
int h = 1;
void update(int index, ll value){
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
	}
}
ll query(int L, int R, int nodenum, int nodeleft, int noderight){
	if (nodeleft > R || noderight < L) return -1;
	else if (L <= nodeleft && noderight <= R) return seg[nodenum];
	int mid = (nodeleft+noderight) / 2;
	return max(query(L, R, nodenum * 2, nodeleft, mid), query(L, R, nodenum * 2 + 1, mid + 1, noderight));
}
bool compare(const pair<int,int> &a,const pair<int,int> &b){
	if (a.first == b.first) return a.second > b.second;
	return a.first<b.first;
}
int main() {
	scanf("%d", &n);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		anspo[i].first = num;
		anspo[i].second = i;
	}
	sort(anspo + 1, anspo + n + 1,compare);
	for (int i = 1; i <= n; i++) {
		Max=query(1,anspo[i].second, 1, 1, h);
		update(anspo[i].second, Max + 1);
	}
	printf("%lld\n",seg[1]);
	return 0;
}
