#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	int a = 3;
	int real = 9;
	int b = 0;
	for (int i = 2; i <= n; i++) {
		b = (a * 2 - 1);
		real = b*b;
		a = b;
	}
	printf("%d\n", real);
	return 0;
}