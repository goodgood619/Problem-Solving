#include <cstdio>
#include <algorithm>
using namespace std;
int n, a, b;
int main(){
	scanf("%d%d%d", &n, &a, &b);
	int cnt = 1;
	while (1) {
		if (a == b) break;
		int amod = a % 2;
		int bmod = b % 2;
		a /= 2;
		b /= 2;
		if (amod != 0) a += 1;
		if (bmod != 0)b += 1;
		if (a != b) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}