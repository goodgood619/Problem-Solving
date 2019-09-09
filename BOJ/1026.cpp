#include <stdio.h>
#include <algorithm>
using namespace std;
int n,sum;
int a[50];
int b[50];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {scanf("%d", &a[i]);}
	for (int i = 0; i < n; i++) { scanf("%d", &b[i]);}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0, j = n - 1; i < n; i++, j--) {
		sum += (a[j] * b[i]);
	}
	printf("%d\n", sum);
	return 0;
}