#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[10001];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		arr[a]++;
	}
	
	for (int i = 0; i <=10000; i++){
		if (arr[i] == 0) continue;
		for (int j= i;arr[j]>0;){ 
			printf("%d\n", j);
			arr[j]--;
		}
	}
	return 0;
}