#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int go(int a, int b) {
	if (a == 0) return b;
	else return go(b%a, a);
}
int main(){
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int Max=go(a, b);
		printf("%d\n", a/Max*b/Max*Max);
	}
	return 0;
}