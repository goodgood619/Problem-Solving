#include <cstdio>
#include <algorithm>
using namespace std;
int arr[50001];
int n,Max,sum;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]); 
	sum += arr[i];
	Max = max(Max, arr[i]);
	}
	printf("%d\n", sum - Max);
	return 0;
}