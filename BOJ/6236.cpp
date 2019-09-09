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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
vector<int> v;
int main() {
	scanf("%d%d", &n, &m);
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
		Max = max(Max, num);
	}
	int left = Max;
	int right = 200000;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		int p = mid;
		for (int i = 0; i < v.size(); i++) {
			if (p >= v[i]) {
				p -= v[i];
			}
			else {
				cnt++;
				p = mid - v[i];
			}
		}
		if (cnt < m) right = mid - 1; //더적게사용됨
		else left = mid + 1;//같거나 그 이상사용됨
	}
	printf("%d\n", left);
	return 0;
}