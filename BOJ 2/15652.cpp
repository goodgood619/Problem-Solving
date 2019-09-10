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
// nPm
map<vector<int>, int> check;
vector<int> v, temp, back;
void go(int index, int cnt, int depth) {
	if (cnt == depth) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	for (int i = index; i <n; i++) {
		ans[cnt] = i + 1;
		//v.push_back(i + 1);
		go(i, cnt + 1, depth);
		//v.pop_back();
		ans[cnt] = 0;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	go(0, 0, m);
	return 0;
}