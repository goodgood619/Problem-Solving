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
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
vector<P> v;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back({ x,y });
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int here = i,next=(i+1)%v.size();
		sum += abs(v[here].first - v[next].first) + abs(v[here].second - v[next].second);
	}
	printf("%d\n", sum);
	return 0;
}