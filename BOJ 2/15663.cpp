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
map<vector<int>, int> m;
vector<int> v,temp;
bool visited[10];
int n,k;
void go(int index, int cnt, int depth) {
	if (cnt == depth) {
		if (m.count(temp) == 0) {
			m[temp]++;
		}
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			go(index + 1, cnt + 1, depth);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	go(0, 0, k);
	map<vector<int>, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		vector<int> t = it->first;
		for (int j = 0; j < t.size(); j++) {
			printf("%d ", t[j]);
		}
		printf("\n");
	}
	return 0;
}