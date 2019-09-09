#include <stdio.h>
#include <algorithm>
using namespace std;
int n, q;
int arr[100];
int bin[10000];
int real[100];
int ti[1000];
int k = 1;
int f;
int ind;
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < q; i++)
		scanf("%d", &ti[i]);
	real[0]=arr[0]-1;
	for (int i = 1; i < n; i++){
		arr[i] += arr[i - 1];
		real[i]=(arr[i]- 1);
	}
	for (int i = 0; i < n;i++) {
		int f=real[i];
		while (ind<=f) {
				bin[ind] = k;
				ind++;
		}
		k++;
	}
	for (int i = 0; i < q; i++)
	{
		printf("%d\n", bin[ti[i]]);
	}
	return 0;
}