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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	int left = 0;
	int right = 1;
	int sum = v[left];
	int cnt = 0;
	while (left <= right) {
		if (sum < m) {
			if (right== v.size()) {
				if (left == v.size()) {
					left++;
					continue;
				}
				sum -= v[left];
				left++;
				continue;
			}
			sum += v[right];
			right++;
		}
		else if (sum > m) {
			sum -= v[left];
			left++;
		}
		else if (sum == m) {
			sum -= v[left];
			left++;
			cnt++;
		}
	}
	while (left <= right) {
		if (sum == m) {
			cnt++;
			sum -= v[left];
			left++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}