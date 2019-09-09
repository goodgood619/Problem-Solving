#include <stdio.h>
#include <algorithm>
using namespace std;
int n,sum;
int arr[1000];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if(i<n-1) arr[i + 1] += arr[i];
	}
	printf("%d\n", sum);
	return 0;
}