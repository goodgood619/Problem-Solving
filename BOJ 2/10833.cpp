#include <cstdio>
#include <algorithm>
using namespace std;
int n,sum;
int main(){
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		sum += (b%a);
	}
	printf("%d\n", sum);
	return 0;
}