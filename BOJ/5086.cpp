#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	while (1) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 0 && b == 0) break;
		if (b%a == 0 && b>a) printf("factor\n");
		else if (a%b == 0 && a > b) printf("multiple\n");
		else printf("neither\n");
	}
	return 0;
}