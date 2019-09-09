#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
int arr[1005];
int cnt;
map<int, int> m;
#define INF 999999999
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]);
	m[arr[i]] = 1;
	}
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <=n; i++){
		for (int j = i + 1; j <=n; j++){
			int diff = arr[j] - arr[i];
			int *high = lower_bound(arr + 1, arr + n + 1,arr[j]+diff*2+1);
			int *low = lower_bound(arr + 1, arr + n + 1, arr[j]+diff);
			cnt += (high - low);
		}
	}
	printf("%d\n", cnt);
	return 0;
}