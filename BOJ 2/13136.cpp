#include <stdio.h>
#include <algorithm>
using namespace std;
int n, r, c,cnt;
long long width, height, ans;
int main(){
	scanf("%d%d%d", &r, &c, &n);
	int divide1=r / n;
	int divide2 = c / n;
	int divide3 = r%n;
	int divide4 = c%n;
	if (divide3) {
		width = divide1+ 1;
	}
	else{
		width = divide1;
	}
	if (divide4) {
		height = divide2 + 1;
	}
	else {
		height = divide2;
	}
	ans = width*height;
	printf("%lld\n", ans);
	return 0;
}