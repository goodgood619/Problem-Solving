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
ll x[100];
ll y[100];
ll arr[205];
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(arr, 0, sizeof(arr));
		int n, m;
		scanf("%d%d", &n, &m);
		ll X = 0;
		ll Y = 0;
		for (int i = 1; i <= m; i++) {
			scanf(" %lld", &x[i]);
		}
		for (int i = 1; i <= m; i++) {
			scanf(" %lld", &y[i]);
		}
		for (int i = 1; i <= m; i++) {
			X+=x[i]*pow(10, m - i);
			Y += y[i] * pow(10, m - i);
		}
		for (int i = 1; i <= n; i++) { scanf(" %lld", &arr[i]);}
		for (int i = 1; i <= n; i++) {
			arr[i + n] = arr[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int cnt = 1;
			ll temp = 0;
			for (int j = i; j <= i + m; j++) {
				temp += arr[j] * pow(10, m - cnt);
				cnt++;
			}
			if (temp >= X && temp <= Y) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}