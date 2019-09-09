#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int t;
int go(int a, int b) {
	if (a%b == 0) return b;
	else return go(b%a, a);
}
int main(){
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int i = 1;
		int j = 2;
		while (1){
			if (a == 1) break;
			else {
				if ((a*j) - (b*i) < 0) {
					j++;
					continue;
				}
				else if ((a*j) - (b*i) == 1) {
					a = (a*j) - (b*i);
					b = b*j;
					j++;
					break;
				}
				else if ((a*j) - (b*i) > 1) {
					a = (a*j) - (b*i);
					b = b*j;
					int div=go(a,b);
					if (div != 1) {
						a /= div;
						b /= div;
					}
					j++;
				}
			}
		}
		printf("%d\n", b);
	}
	return 0;
}