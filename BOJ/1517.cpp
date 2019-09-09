#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <math.h>
#include <set>
#include <climits>
using namespace std;
typedef long long ll;
int n;
vector<int> v;
vector<int> temp;
ll merge(int start, int mid, int en) {
	ll cnt = 0;
	int ptr = start;
	int left = start;
	int right = mid + 1;
	while (left <= mid && right <= en) {
		if (v[left] > v[right]) {
			temp[ptr++] = v[right++];
			cnt += (ll)(mid -left + 1);
		}
		else {
			temp[ptr++] = v[left++];
		}
	}
	while (left<= mid) temp[ptr++] = v[left++];
	while (right <= en) temp[ptr++] = v[right++];
	for (int i = start; i <= en; i++) {
		v[i] = temp[i];
	}
	return cnt;
}
ll go(int start, int en) {

	int mid = (start + en) / 2;
	ll cnt = 0;
	if (start == en) return 0;
	cnt += go(start, mid);
	cnt += go(mid + 1, en);
	return cnt + merge(start, mid, en);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%d", &num);
		v.push_back(num);
	}
	temp.resize(n);
	printf("%lld\n", go(0, n - 1));
	return 0;
}