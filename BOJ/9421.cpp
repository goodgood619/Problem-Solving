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
using namespace std;
bool check[1000005];
int n;
int main() {
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (check[i]) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			check[j] = true;
		}
	}
	scanf("%d", &n);
	vector<int> v;
	for (int i = 2; i <= n; i++) {
		if (!check[i]) v.push_back(i);
	}
	vector<int> ans;
	for (int i = 0; i < v.size(); i++) {
		int p = v[i];
		map<int, int> m;
		m[p] = 1;
		int temp=p;
		int ok = 0;
		while (1) {
			 temp = p;
			 int sum = 0;
			 while (temp > 0) {
				 sum += ((temp % 10)*(temp%10));
				 temp /= 10;
			}
			 if (sum == 1) {
				 ok = 1;
				 break;
			 }
			 if (m.count(sum) != 0) {
				 break;
			 }
			 m[sum] = 1;
			 p = sum;
		}
		if (ok) ans.push_back(v[i]);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}