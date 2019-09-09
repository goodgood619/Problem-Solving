#include <stdio.h>
#include <algorithm>
using namespace std;
int E, S,M;
long long cnt;
int main() {
	scanf("%d%d%d", &E, &S, &M);
	int e = 1;
	int s = 1;
	int m = 1;
	while (1) {
		if (e == E && S == s && M == m) break;
		e += 1;
		if (e > 15) { e %= 15;}
		s += 1;
		if (s > 28) { s %= 28; }
		m += 1;
		if (m > 19) { m %= 19; }
		cnt++;
	}
	printf("%lld\n", cnt+1);
	return 0;
}