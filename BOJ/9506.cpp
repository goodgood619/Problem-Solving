#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
int n;
int arr[10000];
int main(){
	while (1){
		int p = 1;
		int sum = 0;
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		if (n == -1) break;
		arr[p] = 1;
		p++;
		for (int i = 2; i <= sqrt(n); i++){
			if (n%i == 0) {
				arr[p++] = i;
				arr[p++] = n / i;
			}
		}
		sort(arr, arr + p);
		for (int i = 1; i < p; i++) {
			sum += arr[i];
		}
		if (sum != n) printf("%d is NOT perfect.\n", n);
		else {
			printf("%d = ",n);
			for (int i = 1; i < p; i++){
				if (i == p - 1) printf("%d\n", arr[i]);
				else printf("%d + ", arr[i]);
			}
		}

	}
	return 0;
}