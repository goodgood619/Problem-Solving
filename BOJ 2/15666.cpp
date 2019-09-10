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
	if (cnt==depth) {
		if (check.count(v) == 0) {
			check[v] = 1;
		}
		return;
	}
	for (int i = index; i <n; i++){
			v.push_back(temp[i]);
			go(i, cnt + 1, depth);
			v.pop_back();
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		temp.push_back(num);
	}
	sort(temp.begin(), temp.end());
	go(0, 0, m);
	map<vector<int>, int>::iterator it;
	for (it = check.begin(); it != check.end(); it++) {
		for (int i = 0; i < it->first.size(); i++) {
			printf("%d ", it->first[i]);
		}
		printf("\n");
	}
	return 0;
}