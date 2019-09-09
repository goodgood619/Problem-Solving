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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,m;
vector<int> v;
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	int left = 0;
	int right = 100000;
	while (left <= right) {
		int mid = (left + right) / 2;
		int Min = v[0], Max = v[0];
		int cnt = 0;
		for (int i = 1; i < v.size(); i++) {
			Max = max(Max, v[i]);
			Min = min(Min, v[i]);
			if (Max - Min > mid) {
				cnt++;
				Max =v[i];
				Min = v[i];
			}
		}
		if (cnt < m) right = mid - 1;
		else left = mid + 1;
	}
	printf("%d\n", left);
	return 0;
}