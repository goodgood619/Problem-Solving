#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
int arr[500005];
int bucket[715];
int sz = 0;
int n, m;
void start(){
	sz = sqrt(n);
	for (int i = 0; i < n; i++) {
		bucket[i / sz] += arr[i];
	}
}
void update(int index, int value) {
	arr[index]+= value;
	bucket[index/sz]+=value;
}
int query(int here){
	int sum = 0;
	int what = 0;
	while (sum+bucket[what/sz]<=here){
		sum += bucket[what / sz];
		what += sz;
	}
	while (sum<=here){
		sum += arr[what];
		what++;
	}
	return what;
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	start();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int what;
		scanf("%d", &what);
		if (what == 1) {
			int index,value;
			scanf("%d%d", &index, &value);
			update(index-1,value);
		}
		else {
			int find;
			scanf("%d", &find);
			int ans = query(find-1);
			printf("%d\n", ans);
		}
	}
	return 0;
}