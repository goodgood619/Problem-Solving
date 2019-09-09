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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, bool>> PPP;
int n, k;
int main() {
	string s;
	cin >> s;
	cin >> k;
	int length = s.size();
	ll sum = 0;
	vector<ll> temp;
	temp.push_back(1);
	for (int i = 1; i <= length; i++) {
		temp.push_back(pow(10, i - 1));
	}
	for (int i = 0; i < length; i++) {
		sum += (s[i] - '0')*pow(10, length - i - 1);
	}
	ll cnt = 0;
	for (int i = 1; i <= length - 1; i++) {
		cnt += ((9 * pow(10, i - 1))*i);
	}
	cnt += ((sum - temp[length] + 1)*length);
	if ((int)cnt < k) {
		printf("-1\n");
		return 0;
	}
	ll t = 0;
	for (int i = 1; i <= length - 1; i++) {
		t += (9 * pow(10, i - 1)*i);
		if ((int)t > k) {
			t-= (9 * pow(10, i - 1)*i);
			length = i;
			break;
		}
	}
	int start = pow(10, length - 1);
	int ans = 0;
	for (;;) {
		t += length;
		if (t >= k) {
			t -= length;
			vector<int> v;
			int p = start;
			while (p > 0) {
				v.push_back(p% 10);
				p /= 10;
			}
			reverse(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++) {
				int num = v[i];
				t++;
				if (t == k) {
					ans = num;
					break;
				}
			}
			break;
		}
		start++;
	}
	printf("%d\n", ans);
	return 0;
}