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
typedef pair<ll,ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
vector<P> v;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	ll sum = v[0].second - v[0].first;
	ll hx = v[0].first, hy = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		ll nx = v[i].first, ny = v[i].second;
		if (hx == nx) {
			if (hy > ny) {
				continue;
			}
			else if (hy == ny) {
				continue;
			}
			else {
				sum += (ny - hy);
				hy = ny;
			}
		}
		else {
			if (hy > ny) { //그냥안겹침
				continue;
			}
			else if (hy == ny) { //그냥 안겹침
				continue;
			}
			else if(hy<ny && nx<=hy){ // 최대 점까지는 겹침
				sum += (ny-hy);
				hy = ny;
			}
			else if (hy<ny && nx>hy) { //점 조차도 안겹침
				sum += (ny - nx);
				hy = ny;
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}