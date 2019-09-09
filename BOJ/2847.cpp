#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[105];
int n;
int main(){
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]);}
	for (int i = n; i >= 2; i--) {
		int diff = arr[i] - arr[i - 1];
		if (diff <= 0) {
			int a = abs(diff) + 1;
			arr[i - 1] -= a;
			sum += a;
		}
		else continue;
	}
	printf("%d\n", sum);
	return 0;
}