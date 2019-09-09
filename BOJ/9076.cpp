#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int arr[5];
int main(){
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 5; i++) { scanf("%d", &arr[i]);}
		sort(arr, arr + 5);
		arr[0] = 0;
		arr[4] = 0;
		if (arr[3] - arr[1] > 3) { printf("KIN\n");}
		else printf("%d\n", arr[1] + arr[2] + arr[3]);
	}
	return 0;
}