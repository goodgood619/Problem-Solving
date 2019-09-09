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
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int n, k;
int leng[1005];
bool visited[1005];
int route[1005];
map<int, int> m;
map<int, int> mm;
vector<vector<int>> a;
queue <int> q;
void bfs(int here) {
	q.push(here);
	visited[here] = true;
	while (!q.empty()){
		int here = q.front();
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			if (!visited[next]){
				visited[next] = true;
				q.push(next);
				route[next] = here;
			}
		}
	}
}
int main(){
	scanf("%d%d", &n,&k);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++){
		string s;
		for (int j = 1; j <= k; j++) {
			char c;
			scanf(" %c", &c);
			s.push_back(c);
		}
		int sum = 0;
		int length = s.size();
		for (int i = 0; i < length; i++) {
			sum += (s[i] - '0')*pow(2, length - 1 - i);
		}
		m[sum] = i;
		mm[i] = sum;
		leng[i] = length;
	}
	
	for (int i = 1; i <= n; i++) {
		int value = mm[i];
		int XOR = 1;
		int cnt = leng[i];
		int p = value;
		while (cnt--){
			value ^= XOR;
			if (m.count(value)!=0) {
				int next = m[value];
				a[i].push_back(next);
			}
			XOR *= 2;
			value = p;
		}
	}

	int st, en;
	scanf("%d%d", &st, &en);
	bfs(st);
	if (!visited[en]) printf("-1\n");
	else {
		int p = en;
		vector<int> ans;
		ans.push_back(p);
		while (p != st) {
			ans.push_back(route[p]);
			p = route[p];
		}
		reverse(ans.begin(), ans.end());
		int length = ans.size();
		for (int i = 0; i < length; i++) {
			printf("%d ", ans[i]);
		}
	}
	return 0;
}