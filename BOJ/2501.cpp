#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int n, k,p;
int arr[20000];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= sqrt(n); i++) {
		if (n%i == 0){
			if (i != n / i) {
				int ahr = n / i;
				arr[p++] = i;
				arr[p++] = ahr;
			}
			else arr[p++] = i;
		}
	}
	sort(arr, arr + p);
	if (arr[k-1] == 0) printf("0\n");
	else printf("%d\n", arr[k-1]);
	return 0;
}