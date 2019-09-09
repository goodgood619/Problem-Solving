#include <cstdio>
#include <algorithm>
using namespace std;
int a, b;
int go(int a, int b) {
	if (a%b == 0) return b;
	else return go(b, a%b);
}
int main(){
	scanf("%d:%d", &a, &b);
	int ans=go(a,b);
	printf("%d:%d\n", a / ans, b / ans);
	return 0;
}