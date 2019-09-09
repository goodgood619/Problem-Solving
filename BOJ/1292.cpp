#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> seg;
int n, m;
int update(int index, int value, int node, int nodeleft, int noderight) {
	if (index<nodeleft || index>noderight) return seg[node];
	if (nodeleft == noderight) {
		seg[node] = value;
		return seg[node];
	}
	int mid = (nodeleft + noderight) / 2;
	seg[node]=update(index, value, node * 2, nodeleft, mid) + update(index, value, node * 2 + 1, mid + 1, noderight);
	return seg[node];
}
int query(int left, int right, int node, int nodeleft, int noderight) {
	if (right<nodeleft || left>noderight) return 0;
	if (left <= nodeleft && noderight <= right)return seg[node];
	int mid = (nodeleft + noderight) / 2;
	return query(left, right, node * 2, nodeleft, mid) + query(left, right, node * 2 + 1, mid + 1, noderight);
}
int main(){
	seg.resize(5000,0);
	int k = 1;
	for (int i = 1; i <= 1000;){
		for (int j = i; j <i + k; j++) {
			update(j, k, 1, 1,1000);
		}
		i = i + k;
		k++;
	}

		int left, right;
		scanf("%d%d", &left, &right);
		int ans = query(left, right, 1, 1,1000);
		printf("%d\n", ans);
	return 0;
}