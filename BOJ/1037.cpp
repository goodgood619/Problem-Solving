#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	int Min = 10000000;
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		Min = min(Min, num);
		Max = max(Max, num);
	}
	printf("%d\n", Min*Max);
	return 0;
}