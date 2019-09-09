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
typedef pair<pair<int, int>, pair<int,int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n, p;
int main() {
	scanf("%d%d", &n, &p);
	stack<P> s[8];
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		if (s[first].empty()) {
			s[first].push({ first,second });
			cnt++;
		}
		else {
			if (s[first].top().second < second) {
				s[first].push({ first,second });
				cnt++;
			}
			else if(s[first].top().second==second){
				continue;
			}
			else {
				while (!s[first].empty() && s[first].top().second > second) {
					s[first].pop();
					cnt++;
				}
				if (!s[first].empty() && s[first].top().second == second) continue;
				else {
					s[first].push({first,second});
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}