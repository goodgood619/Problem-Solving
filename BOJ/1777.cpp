#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> seg;
int perm[100005];
int PP[100005];
int h = 1;
void update(int index, int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
int query(int what,int nodenum,int nodeleft, int noderight){
	int mid = (nodeleft + noderight) / 2;
	if (nodeleft == noderight) return nodeleft;
	if (seg[nodenum*2] >= what) return query(what, nodenum * 2, nodeleft, mid);
	else return query(what - seg[nodenum*2], nodenum * 2+1, mid + 1, noderight);
}
int main(){
	int n;
	scanf("%d", &n);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		update(i,1);
	}
	for (int i = 1; i <= n; i++) { scanf("%d", &PP[i]); }
	int p = n;
	for (int i = n; i>=1;i--) {
		int cnt = PP[i];
		int position = query(p-cnt, 1, 1, h);
		perm[position] = i;
		update(position, 0);
		p--;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", perm[i]);
	}
	return 0;
}