#include <stdio.h>
#include <algorithm>
using namespace std;
int n,x;
int arr[10001];
int main() {
	scanf("%d%d", &n,&x);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) {
		if (arr[i] < x)
		{
			printf("%d ", arr[i]);
		}
	}
	
	return 0;
}