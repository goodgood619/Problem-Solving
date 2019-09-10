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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int n, l, r, x,ans;
int arr[16];
bool visited[16];
vector<int> v;
void go(int index,int cnt, int depth) {
	if (cnt == depth) {
		int Min = 1e9, Max = 0,sum=0;
		for (int i = 0; i < v.size(); i++) {
			Min = min(Min, v[i]);
			Max = max(Max, v[i]);
			sum += v[i];
		}
		if (Max - Min >= x && sum >= l && sum <= r) ans++;
		return;
	}
	
	for (int i = index; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(arr[i]);
			go(i + 1, cnt + 1, depth);
			v.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {
	scanf("%d%d%d%d", &n, &l, &r, &x);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	for (int i = 2; i <= n; i++) {
		go(0,0,i);
	}
	printf("%d\n", ans);
	return 0;
}