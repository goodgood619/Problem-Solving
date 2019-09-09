#include <cstdio>
#include <algorithm>
using namespace std;
int arr[500005];
int n,m;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int num;
		scanf("%d", &num);
		int *idx = lower_bound(arr + 1, arr + n + 1, num);
		if (*idx == num) printf("1 ");
		else printf("0 ");
	}
	return 0;
}