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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,m;
vector<int> v;
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d", &n,&m);
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	int left = 0, right = 1e9,ans=1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		int nleft = v[0] - mid, nright = v[0] + mid;
		int no = 0;
		if (nleft > 0) no = 1;
		for (int i = 1; i < v.size(); i++) {
			int nnleft = v[i] - mid, nnright = v[i] + mid;
			if (nnleft > nright) {
				no = 1;
				break;
			}
			else {
				nleft = nnleft, nright = nnright;
			}
		}
		if (nright < n) no = 1;
		if (no) left = mid + 1;
		else {
			ans = min(ans,mid);
			right = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}