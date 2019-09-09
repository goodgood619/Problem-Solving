#include <cstdio>
#include <algorithm>
using namespace std;
int arr[21];
int main(){
	for (int i = 1; i <= 20; i++) { arr[i] = i;}
	for (int i = 1; i <= 10; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int j = a, k = b; j <= k; j++, k--) {
			int temp = arr[j];
			arr[j] = arr[k];
			arr[k] = temp;
		}
	}
	for (int i = 1; i <= 20; i++)
		printf("%d ", arr[i]);
	return 0;
}