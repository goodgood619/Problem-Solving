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
int n;
vector<int> v;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int Max = -1e9;
	for (int i = 1; i < v.size() - 1; i++) {
		int mid = i;
		int leftmin = v[0], rightmin = v[mid + 1];
		int leftmax = v[mid - 1], rightmax = v[v.size() - 1];
		int Min = leftmin + rightmin + v[mid], Min2 = leftmax + rightmax + v[mid];
		Max = max(Max, max(abs(Min - 3 * v[mid]), abs(Min2 - 3 * v[mid])));
	}
	printf("%d\n", Max);
	return 0;
}