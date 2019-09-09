#include <stdio.h>
#include <algorithm>
using namespace std;
int m, n,k,idx;
int arr[200];
void go(int m, int n) {
	int a = 1;
	for (int i = a,j=0; a*a<= n; a++,j++){
		arr[j] = a*a;
		idx = j;
		if (arr[j] < m) {
			arr[j] = 0;
		}
	}
}
int main() {
	scanf("%d%d", &m, &n);
	go(m, n);
	int sum = 0;
	int Min = 10000000;
	for (int i = 0; i <=idx; i++) {
		if (arr[i] == 0) continue;
		if (Min > arr[i]) {
			Min = arr[i];
		}
		sum += arr[i];
	}
	if (sum != 0) {
		printf("%d\n", sum);
		printf("%d\n", Min);
	}
	else printf("-1\n");
	return 0;
}
