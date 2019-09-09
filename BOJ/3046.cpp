#include <cstdio>
using namespace std;
int a, b;
int main() {
	scanf("%d%d", &a, &b);
	int ans = b * 2 - a;
	printf("%d\n", ans);
	return 0;
}