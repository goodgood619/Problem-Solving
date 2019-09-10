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
int n, m;
bool visited[10];
int ans[10];
int temp[10];
// nPm
vector<int> v;
void go(int index, int cnt, int depth) {
	if (depth == cnt) {
		for (int i = 0; i < m; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}
	for (int i = index; i < n; i++) {
			v.push_back(temp[i]);
			go(i, cnt + 1, depth);
			v.pop_back();
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp[i]);
	}
	sort(temp, temp + n);
	go(0, 0, m);
	return 0;
}