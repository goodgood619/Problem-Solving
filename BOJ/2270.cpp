#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
#define mod 1000000
int disc[100004];
int disccnt[100004];
int n,one,two,three,q;
long long cnt;
void hanoi(int n,int to){
	int st = disc[n];
	int by = 6 - st - to;
	if (n < 1) return;
	if (st == to) {
		hanoi(n - 1, to);
	}
	else {
		hanoi(n - 1, by);
		cnt = ((cnt + disccnt[n - 1]) % mod);

	}
}
int main(){
	scanf("%d", &n);
	disccnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		disccnt[i] =((disccnt[i-1]*2)%mod);
	}
	scanf("%d%d%d", &one, &two, &three);
	for(int i=1;i<=one;i++){
		scanf("%d", &q);
		disc[q] = 1;
	}
	for (int i = 1; i <= two; i++) {
		scanf("%d", &q);
		disc[q] = 2;
	}
	for (int i = 1; i <= three; i++) {
		scanf("%d", &q);
		disc[q] = 3;
	}
	printf("%d\n", disc[n]);
	hanoi(n - 1, disc[n]);
	printf("%lld\n", cnt);
	return 0;
}