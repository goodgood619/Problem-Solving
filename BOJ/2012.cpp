#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int arr[500000];
long long sum;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]);}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		sum += abs(arr[i] - (i + 1));
	}
	printf("%lld\n", sum);
	return 0;
}