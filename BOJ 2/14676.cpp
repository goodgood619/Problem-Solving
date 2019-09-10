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
typedef pair<int, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int indegree[100005] = { 0, };
	int buildcnt[100005] = { 0, };
	vector<vector<int>> a;
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		indegree[second]++;
	}
	for (int i = 1; i <= k; i++) {
		int choice;
		scanf("%d", &choice);
		if (choice == 1) {
			int make;
			scanf("%d", &make);
			// 만약 건물을 지어야 하는데, 지을수 없는상황?
			if (indegree[make] > 0) {
				printf("Lier!\n");
				return 0;
			}
			buildcnt[make]++;
			// 건물이 지어졌으니, 다음건물을 지을수 있게 도와준다
			for (int i = 0; i < a[make].size(); i++) {
				int next = a[make][i];
				indegree[next]--;
			}
		}
		else {
			int make;
			scanf("%d", &make);
			// 건물을 제거해야하는데 건물이 없다면?
			if (buildcnt[make] == 0) {
				printf("Lier!\n");
				return 0;
			}
			buildcnt[make]--;
			//건물이 아예사라진경우에는 다음건물을 못짓게 해야한다
			if (buildcnt[make] == 0) {
				for (int i = 0; i < a[make].size(); i++) {
					int next = a[make][i];
					indegree[next]++;
				}
			}
		}
	}
	printf("King-God-Emperor\n");
	return 0;
}