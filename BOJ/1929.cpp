#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int m, n,hab;
int prime[1000001];
void go() {
	for (int i = 2; i <= sqrt(1000000); i++){
		if (prime[i] == 0) continue;
		for (int j = i*i; j <= 1000000; j += i) {
			prime[j] = 0;
		}
	}
}
int main(){
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= 1000000; i++)prime[i] = i;
	go();
	for (int i = m; i <= n; i++){
		if (i == 1) continue;
		if (prime[i] != 0) {
			printf("%d\n", prime[i]);
		}
	}
	return 0;
}