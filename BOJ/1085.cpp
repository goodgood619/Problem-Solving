#include <stdio.h>
#include <algorithm>
using namespace std;
int x, y, w, h;
int main(){
	scanf("%d%d%d%d", &x, &y, &w, &h);
	int a = w - x;
	int b = h - y;
	if (a > x) {
		if (b > y) {
			if (x > y) printf("%d\n", y);
			else printf("%d\n", x);
		}
		else {
			if (x > b) printf("%d\n", b);
			else printf("%d\n", x);
		}
	}
	else {
		if (b > y) {
			if (a > y) printf("%d\n", y);
			else printf("%d\n", a);
		}
		else {
			if (a > b) printf("%d\n", b);
			else printf("%d\n", a);
		}
	}
	return 0;
}