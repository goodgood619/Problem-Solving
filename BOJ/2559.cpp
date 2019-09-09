#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[100001];
int n, k;
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]);}
	int left = 1;
	int right = 1;
	int cnt = 0;
	int sum = 0;
	int real = -9999999;
	for (;right<=n+1;) {
		if (cnt < k) {
			sum += arr[right];
			cnt++;
			right++;
		}
		else if (cnt == k) {
			real = max(sum, real);
			sum -= arr[left];
			left++;
			cnt--;
		}
	}
	printf("%d\n", real);
	return 0;
}