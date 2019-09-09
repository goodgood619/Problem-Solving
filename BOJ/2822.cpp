#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[8];
int idx[151];
int temp[5];
int sum,cnt,k;
int main() {
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
		idx[arr[i]] = i+1;
	}
	sort(arr, arr + 8);
	for (int i = 0; i < 8; i++){
		if (i < 3) {
			cnt++; continue;
		}
		else {
			if (idx[arr[i]] != 0) {
				temp[k++] = idx[arr[i]];
			}
			sum += arr[i];
		}
	}
	sort(temp, temp + 5);
	printf("%d\n", sum);
	for (int i = 0; i < 5; i++){
		if (i == 4) printf("%d\n", temp[i]);
		else printf("%d ", temp[i]);
	}
	return 0;
}
