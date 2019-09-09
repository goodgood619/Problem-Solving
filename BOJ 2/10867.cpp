#include <cstdio>
#include <algorithm>
using namespace std;
int n,temp;
int arr[100001];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]);}
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++){
		if (temp == arr[i]) continue;
		for (int j = -1000; j <= 1000; j++) {
			if (arr[i] == j) {
				temp = j;
				printf("%d ",j);
				break;
			}
		}
	}
	return 0;
}