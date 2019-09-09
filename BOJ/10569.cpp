#include <stdio.h>
#include <algorithm>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		int u, v;
		scanf("%d%d", &u, &v);
		int m=2 - u + v;
		printf("%d\n", m);
	}
	return 0;
}