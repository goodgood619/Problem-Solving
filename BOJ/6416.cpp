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
map<int, int> m; // indegree용
map<int, int> check; // 정점갯수
int main() {
	int Case = 1;
	while (1) {
		int here, next;
		scanf("%d%d", &here, &next);
		if (here == -1 && next == -1) break;
		else if(here==0 && next==0){
			if (m.empty()) {
				printf("Case %d is a tree.\n",Case++);
				check.clear();
			}
			else {
				if (check.size() - 1 != m.size()) {
					printf("Case %d is not a tree.\n", Case++);
					check.clear();
					m.clear();
					continue;
				}
				map<int, int>::iterator it;
				int no = 0;
				int ok = 0;
				for (it = check.begin(); it != check.end(); it++) {
					if (m.count(it->first) == 0) { // 루트노드
						ok = 1;
					}
					if (m[it->first] >= 2) { // 들어오는간선갯수 2개이상
						no = 1;
					}
				}
				if (!no && ok) {
					printf("Case %d is a tree.\n", Case++);
					check.clear();
					m.clear();
				}
				else {
					printf("Case %d is not a tree.\n", Case++);
					check.clear();
					m.clear();
				}
			}
		}
		else {
			if (check.count(here) == 0) check[here] = 1;
			if (check.count(next) == 0) check[next] = 1;
			m[next] += 1;
		}
	}
	
	return 0;
}