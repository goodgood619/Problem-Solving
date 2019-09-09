#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[105];
int go(int a, int b) {
	if (a%b == 0) return b;
	else return go(b, a%b);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]);}
	for (int i = 2; i <= n; i++) {
		int Max=go(arr[1], arr[i]);
		printf("%d/%d\n", arr[1] / Max, arr[i] / Max);
	}
	return 0;
}