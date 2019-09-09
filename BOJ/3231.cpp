#include <stdio.h>
#include <algorithm>
using namespace std;
int n,cnt;
int arr[100001];
int idx[100001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		idx[arr[i]] = i;
	}
	for (int i = 1; i <= n-1; i++){
		int index1 = idx[i];
		int index2 = idx[i + 1];
		if (index1 < index2) continue;
		else if (index1 > index2) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}