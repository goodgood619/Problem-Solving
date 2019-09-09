#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int t;
int arr[1000000];
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int n,m;
		scanf("%d", &n);
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		sort(arr, arr + n);
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			int num;
			scanf("%d", &num);
			int *idx = lower_bound(arr, arr + n, num);
			if (*idx == num) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}