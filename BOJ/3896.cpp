#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int isprime[1300000];
void go() {
	for (int i = 2; i <= sqrt(1300000); i++){
		if (isprime[i] == 0) continue;
		for (int j = i*i; j <= 1300000; j += i) {
			isprime[j] = 0;
		}
	}

}

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 2; i <= 1300000; i++) {
		isprime[i] = i;
	}
	go();
	while (t--) {
		int n;
		scanf("%d", &n);
		if (isprime[n] != 0) printf("0\n");
		else{
			int cnt = 1;
			int a = n;
			int b = 0;
			int c = 0;
			for (int i = a;; i++) {
				if (isprime[i] != 0) {
					b = i;
					break;
				}
			}
			for (int i = a;; i--) {
				if (isprime[i] != 0) {
					c = i;
					break;
				}
			}
			printf("%d\n", b - c);
		}
	}
	return 0;
}