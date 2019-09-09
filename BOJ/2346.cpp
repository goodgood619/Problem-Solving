#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
#include <deque>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int indegree[1005];
int value[1005];
int cnt[1005];
deque<P> d;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		d.push_back({ i,num });
	}
	int Size = d.size();
	vector<int> ans;
	while (1) {
		int idx = d.front().first;
		int move = d.front().second;
		ans.push_back(idx);
		d.pop_front();
		if (d.size() == 0) break;
		if (move > 0) {
			move--;
			while (move > 0) {
				d.push_back(d.front());
				d.pop_front();
				move--;
			}
		}
		else {
			while (move < 0) {
				d.push_front(d.back());
				d.pop_back();
				move++;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}