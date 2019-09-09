#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[1000001];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]);}
	sort(arr + 1, arr + n + 1);
	printf("%d %d\n", arr[1], arr[n]);
	return 0;
}