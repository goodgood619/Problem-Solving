#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int prime[250000];
int n;
int main(){
	for (int i = 1; i <= 250000; i++) {
		prime[i] = i;
	}
	for (int i = 2; i <= sqrt(250000); i++){
		if (prime[i] == 0) continue;
		for (int j = i*i; j <= 250000; j += i) {
			prime[j] = 0;
		}
	}
	while (1){
		int cnt = 0;
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = n + 1; i <=2 * n; i++) {
			if (prime[i] == 0) continue;
			else cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}