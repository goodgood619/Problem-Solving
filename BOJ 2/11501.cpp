#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <climits>
#include <map>
#include <functional>
#include <set>
#include <list>
#include <math.h>
using namespace std;
typedef long long ll;
ll arr[1000005];
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		memset(arr, 0, sizeof(arr));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)scanf(" %lld", &arr[i]);
		ll last = arr[n];
		ll sum = 0;
		for (int i = n - 1; i >= 1; i--) {
			if (arr[i] < last) {
				sum += (last - arr[i]);
			}
			else last = arr[i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}