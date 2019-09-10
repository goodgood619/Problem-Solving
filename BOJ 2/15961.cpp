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
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int n, d, k, c;
int arr[6000005];
int sushi[3005];
int main() {
	scanf("%d%d%d%d", &n, &d, &k, &c);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &arr[i]);
		arr[i + n] = arr[i];
	}
	int ans = 1;
	sushi[c]++;
	int cnt = 0,eat=1,front=1;
	for (int i = 1; i <= n + n; i++) {
		int temp = sushi[arr[i]];
		if (cnt <= k) {
			sushi[arr[i]]++;
			cnt++;
			if (temp == 0 && sushi[arr[i]] > 0) {
				eat++;
			}
			ans = max(ans, eat);
			if (cnt == k) {
				int temp2 = sushi[arr[front]];
				sushi[arr[front]]--;
				if (temp2 > 0 && sushi[arr[front]] == 0) {
					eat--;
				}
				cnt--;
				front++;
				ans = max(ans, eat);
			}
		}
		
	}
	printf("%d\n", ans);
	return 0;
}