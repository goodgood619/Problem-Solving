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
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int main() {
	priority_queue<int, vector<int>> pq;
	vector<int> v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	vector<int> temp;
	for (int i = 0; i < v.size(); i++) {
		if (temp.size() == 0) {
			temp.push_back(v[i]);
			continue;
		}
		else {
			if (temp.size() > v[i]) {
				continue;
			}
			else {
				temp.push_back(v[i]);
			}
		}
	}
	printf("%d\n", temp.size());
	return 0;
}