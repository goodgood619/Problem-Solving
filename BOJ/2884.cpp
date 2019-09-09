#include <cstdio>
#include <algorithm>
using namespace std;
int a, b;
int main(){
	scanf("%d%d", &a, &b);
	if (b < 45) {
		b=b - 45 + 60;
		a -= 1;
		if (a < 0) a += 24;
	}
	else b -= 45;
	printf("%d %d\n", a, b);
	return 0;
}