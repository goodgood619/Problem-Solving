#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
typedef long long ll;
vector <ll> minseg;
vector <ll> maxseg;
ll Min = 99999999999999;
ll minupdate(int index, ll num, int node, int nodeleft, int noderight) {
	if (index<nodeleft || index>noderight) return minseg[node];
	if (nodeleft == noderight) {
		minseg[node] = num;
		return minseg[node];
	}
	int mid = (nodeleft + noderight) / 2;
	minseg[node] = min(minupdate(index, num, node * 2, nodeleft, mid), minupdate(index, num, node * 2 + 1, mid + 1, noderight));
	return minseg[node];
}
ll mingo(int left,int right,int node,int nodeleft,int noderight){
	if (left > noderight || right < nodeleft) return Min;
	if (left <= nodeleft && noderight <= right) return minseg[node];
	int mid = (nodeleft + noderight) / 2;
	return min(mingo(left, right, node * 2, nodeleft, mid), mingo(left, right, node * 2 + 1, mid + 1, noderight));
}
int main(){
	scanf("%d%d", &n, &m);
	int h = 1;
	while (h < n) h *= 2;
	minseg.resize(h * 2, Min);
	maxseg.resize(h * 2, 0);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		minupdate(i,num,1,1,h);
	}
	for (int i = 1; i <= m; i++) {
		int fleft, fright;
		scanf("%d%d", &fleft, &fright);
		ll M=mingo(fleft,fright,1,1,h);
		printf("%lld\n",M);
	}
	return 0;
}