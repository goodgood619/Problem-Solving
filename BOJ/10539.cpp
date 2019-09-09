#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
long long arr[101];
long long real[101];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%lld", &arr[i]);}
	if (n == 1) printf("%lld\n", arr[n]);
	else {
		for (int i = 1; i <= n; i++){
			long long x = 0;
			x = i*arr[i];
			for (int j = 1; j<i; j++) {
				x-= real[j];
			}
			real[i] = x;
			printf("%lld ", real[i]);
		}
	}
	return 0;
}