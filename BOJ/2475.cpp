#include <cstdio>
#include <algorithm>
using namespace std;
int arr[5];
int sum;
int main() {
	for (int i = 0; i < 5; i++) { scanf("%d", &arr[i]);
	sum += arr[i] * arr[i];
	}
	printf("%d\n", sum % 10);
	return 0;
}