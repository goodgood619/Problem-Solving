#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
vector<P> v;
map<int, int> m;
int main() {
	scanf("%d", &n);
	int Max = 0;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		int k, height;
		scanf("%d%d", &k, &height);
		v.push_back({ k,height });
		m[k] = height;
		
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (Max < v[i].second) {
			Max = v[i].second;
			idx = v[i].first;
		}
	}
	int sum = 0;
	int maxheight = 0;
	//왼쪽에서 부터 최대높이까지 향하기 더하기
	for (int i = 1; i < idx; i++) {
		maxheight = max(maxheight, m[i]);
		sum += maxheight;
	}
	//오른쪽에서부터 최대높이까지 향하기
	maxheight = 0;
	for (int i = 1000; i > idx; i--) {
		maxheight = max(maxheight, m[i]);
		sum += maxheight;
	}
	sum += Max;
	printf("%d\n", sum);
	return 0;
}