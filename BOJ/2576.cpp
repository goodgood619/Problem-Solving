#include <stdio.h>
#include <algorithm>
using namespace std;
int Min = 101;
int sum;
int main() {
	int t = 7;
	while (t--){
		int a;
		scanf("%d", &a);
		if (a % 2 == 1) {
			sum += a;
			Min = min(a, Min);
		}
		else continue;
	}
	if (sum == 0) printf("-1\n");
	else { printf("%d\n",sum);
	printf("%d\n", Min);
	}
	return 0;
}