#include <stdio.h>
#include <algorithm>
using namespace std;
int n,sum;
int arr[1010];
int main() {
	scanf("%d", &n);
	for (int i = 0; i <n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	if (arr[0] == 1)
		sum = arr[0];
	else
		sum = 0;
	if (sum != 0)
	{
		for (int i = 0; i < n; i++) {
			if (sum+1 < arr[i + 1]) break;
			else
				sum += arr[i + 1];
		}
		printf("%d\n", sum + 1);
	}
	else
	printf("%d\n", sum + 1);
	return 0;
}