#include <stdio.h>
#include <algorithm>
using namespace std;
long long s,sum;
int idx;
int ans = 999999;
int arr[100001];
int main() {
	scanf("%lld", &s);
	for (int i = 1;; i++){
		sum += i;
		arr[i] = i;
		if (sum>s){
			idx = i-1;
			break;
		}
	}
	printf("%d\n", idx);
	return 0;
}