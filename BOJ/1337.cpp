
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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
int arr[10001];
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);
	int Max = 1;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		Max = 1;
		for (int j = 1; i+j<=n&&j <5; j++) {
			if (arr[i + j] < arr[i] + 5) Max++;
		}
		ans = max(ans, Max);
	}
	printf("%d\n", 5 - ans);
	return 0;
}
