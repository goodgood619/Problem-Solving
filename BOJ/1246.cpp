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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = {-1,1,0,0 };
int goy[4] = {0,0,-1,1 };
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	vector<int> v;
	for (int i = 1; i <= k; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int Max = 0, idx = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		int cnt = 0;
		int sum = 0;
		for (int j = i; j < v.size(); j++) {
			sum += v[i];
			cnt++;
		}
		if (cnt > n) continue;
		if (Max < sum) {
			Max = sum;
			idx = v[i];
		}
	}
	printf("%d %d\n", idx, Max);
	return 0;
}