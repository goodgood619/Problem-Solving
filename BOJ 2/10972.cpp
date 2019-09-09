#include <cstdio>
#include <algorithm>
using namespace std;
int arr[10000];
int temp[10000];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]);
	temp[i] = arr[i];
	}
	if (next_permutation(temp, temp + n)) {
		for (int i = 0; i < n; i++) {
			printf("%d ", temp[i]);
		}
	}
	else printf("-1\n");
	return 0;
}