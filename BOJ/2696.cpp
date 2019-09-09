#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,k;
int arr[10001];
int temp[10001];
int ans[10001];
int main(){
	scanf("%d", &t);
	while (t--){
		memset(arr, 0, sizeof(arr));
		memset(temp, 0, sizeof(temp));
		memset(ans, 0, sizeof(ans));
		int n;
		scanf("%d", &n);
		int cnt = 0;
		k = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
			cnt++;
			if (cnt % 2 == 1) {
				int p = 1;
				for (int j = 1; j <= i; j++) {
					temp[p++] = arr[j];
				}
				sort(temp + 1, temp + p);
				ans[k++] = temp[(cnt/2)+1];
				memset(temp, 0, sizeof(temp));
			}
		}
		printf("%d\n", k);
		int q = 0;
		for (int i = 0; i < k; i++){
			if (q % 10 == 0 && q != 0) {
				printf("\n");
				printf("%d ", ans[i]);
				q++;
			}
			else {
				printf("%d ", ans[i]);
				q++;
			}
		}
		printf("\n");
	}
	return 0;
}