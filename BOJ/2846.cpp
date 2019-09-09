#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1005];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int length = 1;
	int Min = arr[1];
	int Max = arr[1];
	int diff = 0;
	for (int i = 2; i <= n; i++) {
		if (Max < arr[i]){
			length++;
			Max = arr[i];
			if (length >= 2) {
				diff = max(diff, Max - Min);
			}
		}
		else {
			Min = arr[i];
			Max = arr[i];
			length = 1;
		}
	}
	printf("%d\n", diff);
	return 0;
}