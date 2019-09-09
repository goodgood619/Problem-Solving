#include <cstdio>
#include <algorithm>
using namespace std;
int a, b,ptr;
int cnt[10];
int main(){
	scanf("%d%d", &a, &b);
	int p = a;
	int q = b;
	while (p > 0 || q > 0){
		int mod1 = p % 10;
		int mod2 = q % 10;
		int ans1 = mod1 + mod2;
		cnt[ptr++] = ans1;
		p /= 10;
		q /= 10;
	}
	for (int i = ptr - 1; i >= 0; i--) {
		printf("%d", cnt[i]);
	}
	return 0;
}