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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
vector<vector<int>> a;
vector<int> v;
int arr[55];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int Max = 1;
	int cnt = 1;
	int cnt2 = 1;
	int curheight = arr[1];
	for (int i = 2; i <= n; i++) {
		if (curheight < arr[i]) {
			curheight = arr[i];
			cnt++;
		}
	}
	curheight = arr[n];
	for (int i = n - 1; i >= 1; i--) {
		if (curheight < arr[i]) {
			curheight = arr[i];
			cnt2++;
		}
	}
	printf("%d\n%d\n", cnt, cnt2);
	return 0;
}