#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int movie[300005];
vector<int> seg;
int t,m,n,h=1,h2=1;
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
	else if (L <= nodeleft && noderight <= R) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return query(nodenum * 2, L, R, nodeleft, mid) + query(nodenum * 2 + 1, L, R, mid + 1, noderight);
}
int main(){
	scanf("%d", &t);
	while (t--){
		memset(movie, 0, sizeof(movie));
		h = 1;
		scanf("%d%d",&n,&m);
		while (h < n+m) h *= 2;
		seg.clear();
		h*=4;
		seg.resize(2*h*h2*2);
		int p = n;
		for (int i = 1; i <= n; i++) {
			movie[i] = p;
			update(p, 1);
			p--;
		}
		for (int i = 1; i <= m; i++){
			int mi;
			scanf("%d", &mi);
			int ans = query(1, movie[mi], h, 1, h) - 1;
			printf("%d ", ans);
			update(movie[mi], 0);
			update(n+1, 1);
			movie[mi] =n+1;
			n++;
		}
		printf("\n");
	}
	return 0;
}