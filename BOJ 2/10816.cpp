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
int n,k;
vector<int> v;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		int num;
		scanf("%d", &num);
		vector<int>::iterator it, it2;
		it = lower_bound(v.begin(), v.end(), num);
		it2 = upper_bound(v.begin(), v.end(), num);
		printf("%d ", it2 - it);
	}
	return 0;
}