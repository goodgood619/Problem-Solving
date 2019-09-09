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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int h, n;
map<int, int> m;
int main() {
	scanf("%d%d", &n, &h);
	vector<int> v1, v2;
	for (int i = 1; i <= n / 2; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		v1.push_back(first);
		v2.push_back(second);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	vector<int>::iterator it, it2;
	int Min = 1e9;
	for (int i = 1; i <= h; i++) {
		int ans1 = -1, ans2 = -1;
		it = lower_bound(v1.begin(), v1.end(), i);
		it2 = lower_bound(v2.begin(), v2.end(), h-i+1);
		if (it == v1.end()) ans1 = 0;
		else ans1 = v1.end()- it;
		if (it2 == v2.end()) ans2 = 0;
		else ans2 = v2.end() - it2;
		if (Min > ans1 + ans2) {
			Min = ans1 + ans2;
			m[Min]++;
		}
		else if(Min==ans1+ans2){
			m[Min]++;
		}
	}
	printf("%d %d\n", Min, m[Min]);
	return 0;
}