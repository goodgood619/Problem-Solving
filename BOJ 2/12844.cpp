#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
int h = 1;
int n, m, k;
typedef struct {
	ll value;
	ll lazy;
}Seg;
Seg seg[2500005];
void initupdate(int index, ll value) {
	index += h - 1;
	seg[index].value = value;
	while (index > 1) {
		index /= 2;
		seg[index].value = seg[index * 2].value^seg[index * 2 + 1].value;
	}
}
void update(int nodenum, int L, int R, ll value, int nodeleft, int noderight) {
	// lazy가 남아있을때
	if (seg[nodenum].lazy != 0) {
		if (nodeleft<noderight) {
			seg[nodenum * 2].lazy ^= seg[nodenum].lazy;
			seg[nodenum * 2 + 1].lazy^= seg[nodenum].lazy;
		}
		else seg[nodenum].value^= seg[nodenum].lazy;
		seg[nodenum].lazy = 0;
	}
	if (nodeleft > R || noderight < L) return;
	else if (L <= nodeleft && noderight <= R){
		if (nodeleft<noderight){
			seg[nodenum * 2].lazy^= value;
			seg[nodenum * 2 + 1].lazy^= value;
		}
		else seg[nodenum].value^= value;
		return;
	}
	int mid = (nodeleft + noderight)/2;
	update(nodenum * 2, L, R, value, nodeleft, mid);
	update(nodenum * 2 + 1, L, R, value, mid + 1, noderight);
	//맨마지막에는 최종적인 상태를 업데이트해야하니까 추가되어야함
	seg[nodenum].value = seg[nodenum * 2].value^seg[nodenum * 2 + 1].value;
}
ll query(int nodenum, int L, int R, int nodeleft, int noderight){
	if (seg[nodenum].lazy != 0) {
		if (nodeleft<noderight) {
			seg[nodenum * 2].lazy^= seg[nodenum].lazy;
			seg[nodenum * 2 + 1].lazy^= seg[nodenum].lazy;
		}
		else seg[nodenum].value ^= seg[nodenum].lazy;
		seg[nodenum].lazy = 0;
	}
	if (nodeleft > R || noderight < L) return 0;
	else if (L <= nodeleft && noderight <= R) return seg[nodenum].value;
	int mid = (nodeleft + noderight) / 2;
	return query(nodenum * 2, L, R, nodeleft, mid)^query(nodenum * 2 + 1, L, R, mid + 1, noderight);
}
int main(){
	scanf("%d", &n);
	while (h < n) h *= 2;
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		initupdate(i,num);
	}
	scanf("%d", &m);
	for (int i = 1; i <=m; i++) {
		int what;
		scanf("%d", &what);
		if (what == 1){
			int first, second;
			ll value;
			scanf("%d%d%lld", &first, &second, &value);
			first += 1;
			second += 1;
			if (first > second){
				int temp = first;
				first = second;
				second = temp;
			}
			update(1,first, second, value,1, h);
		}
		else if (what == 2) {
			int left, right;
			scanf("%d%d", &left, &right);
			left += 1;
			right += 1;
			if (left > right) {
				int temp = left;
				left = right;
				right = temp;
			}
			ll ans=query(1, left, right,1,h);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
