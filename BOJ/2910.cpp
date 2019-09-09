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
int n,c;
map<int, int> m;
vector<int> v;
vector<int> bindo[1005];
map<int, int> check;
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		if (m.count(num) == 0) {
			m[num]++;
		}
		else m[num] += 1;
		v.push_back(num);
	}
	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		int num = it->first;
		int cnt = it->second;
		bindo[cnt].push_back(num);
	}
	for (int i = 1000; i >= 1; i--) {
		if (bindo[i].size() == 0) continue;
		else {
			for (int k = 0; k < v.size(); k++) {
				int num = v[k];
				for (int j = 0; j < bindo[i].size(); j++) {
					int a = bindo[i][j];
					if (check.count(a) != 0) continue;
					if (num == a) {
						for (int p = 1; p <= i; p++) {
							printf("%d ", a);
						}
						if (check.count(a) == 0) check[a]++;
					}
				}
			}
		}
	}
	return 0;
}