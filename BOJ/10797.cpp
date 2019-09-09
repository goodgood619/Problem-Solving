#include <stdio.h>
#include <algorithm>
using namespace std;
int n,cnt;
int arr[5];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == n) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}