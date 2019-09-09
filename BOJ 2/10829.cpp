#include <stdio.h>
#include <algorithm>
using namespace std;
long long n;
void go(long long n) {
	if (n == 0) {
		printf("%lld", n);
	}
	else if (n == 1) {
		printf("%lld", n);
	}
	else {
		go(n / 2);
		go(n % 2);
	}
}
int main(){
	scanf("%lld", &n);
	go(n);
	printf("\n");
	return 0;
}