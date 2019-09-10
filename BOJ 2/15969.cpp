#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
int arr[1005];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);
	printf("%d\n", arr[n] - arr[1]);
	
	return 0;
}