#include <stdio.h>
#include <algorithm>
using namespace std;
int e, f, c;
int coke,cnt;
int main() {
	scanf("%d%d%d", &e, &f, &c);
	int bottle = e + f;
	for (;;) {
		if (bottle < c) break;
		cnt += (bottle / c);
		bottle = (bottle / c) + (bottle%c);
	}
	printf("%d\n", cnt);
	return 0;
}