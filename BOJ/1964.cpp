#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
long long hab;
int main(){
	scanf("%d", &n);
	hab = 5;
	for (int i = 2; i <= n; i++) {
		hab += ((i * 3) + 1);
		hab = hab % 45678;
	}
	printf("%lld\n", hab);
	return 0;
}