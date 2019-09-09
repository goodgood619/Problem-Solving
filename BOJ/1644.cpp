
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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
bool check[4000005];
int main() {
	vector<int> v;
	for (int i = 2; i <= sqrt(4000000); i++) {
		if (check[i]) continue;
		for (int j = i*i; j <= 4000000; j += i) {
			check[j] = true;
		}
	}
	for (int i = 2; i <= 4000000; i++) {
		if (!check[i]) v.push_back(i);
	}
	scanf("%d", &n);
	int sum = 0;
	int cnt = 0;
	int left = 0;
	int right = 0;
	while (left <=right) {
		if (sum > n) {
			sum -= v[left];
			left++;
			if (left == v.size()) break;
		}
		else if (sum == n) {
			cnt++;
			sum -= v[left];
			left++;
			if (left == v.size()) break;
		}
		else {
			sum += v[right];
			right++;
			if (right == v.size()) break;
		}
	}
	printf("%d\n", cnt);
	return 0;
}