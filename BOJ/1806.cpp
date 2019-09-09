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
int n, s;
vector<int> v;
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	int left = 0;
	int right = 0;
	int length = 1e9;
	int sum = v[left];
	while (left <= right) {
		if (sum < s) {
			if (right>= v.size()-1) {
				if (left == v.size()) {
					left++;
					continue;
				}
				sum -= v[left];
				left++;
				continue;
			}
			right++;
			sum += v[right];
		}
		else {
			length = min(length, right - left + 1);
			sum -= v[left];
			left++;

		}
	}
	length == 1e9 ? printf("0\n") : printf("%d\n", length);
	return 0;
}