#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[100010];
int real[100010];
int n;
int k = 1;
long long price = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i <n; i++)
	scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = n-1; i >=0; i--) {
		real[k] = arr[i];
		k++;
	}
	for (int i = 1; i <= n; i++)
	{
		if(i%3!=0)
		price += real[i];
	}
	printf("%lld\n", price);
	return 0;
}