#include <cstdio>
#include <algorithm>
using namespace std;
int arr[6];
int Max,idx,sum;
int main(){
	for (int i = 1; i <= 5; i++){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		sum = 0;
		sum = sum + a + b + c + d;
		if (Max < sum) {
			Max = sum;
			idx = i;
		}
	}
	printf("%d %d\n", idx, Max);
	return 0;
}