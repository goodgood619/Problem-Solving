#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int x = 9999999;
int y = 9999999;
typedef pair<int, int> P;
P anspo[25];
int maxy,maxx,n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num1, num2;
		scanf("%d%d", &num1, &num2);
		x = min(x, num1);
		y = min(y, num2);
		maxx = max(maxx, num1);
		maxy = max(maxy, num2);
	}
	int a = maxx - x;
	int b = maxy - y;
	if (a > b) printf("%d\n", a*a);
	else printf("%d\n", b*b);
	return 0;
}