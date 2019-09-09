#include <cstdio>
#include <algorithm>
using namespace std;
int n,sum;
int Min = 9999999;
int arr[7];
int main(){
	scanf("%d", &n);
	while (n--) {
		sum = 0;
		Min = 9999999;
		for (int i = 0; i < 7; i++) { scanf("%d", &arr[i]); 
		if (arr[i] % 2 == 0) {
			Min=min(arr[i], Min);
			sum += arr[i];
		}
		}
		printf("%d %d\n", sum, Min);
	}
	return 0;
}