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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
vector<vector<int>> a;
int parent[200005];
int n,cnt=1;
bool visited[200005];
int main() {
	scanf("%d", &n);
	a.resize(n / 2 + 1);
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	memset(parent, -1, sizeof(parent));
	for (int i = 0; i < v.size() - 1; i++) {
		int here = v[i],next=v[i+1];
		visited[here] = true;
		if (!visited[next]) {
			visited[next] = true;
			parent[next] = here;
		}
		else {
			cnt++;
			parent[here] = next;
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		parent[i] == -1 ? printf("-1 ") : printf("%d ", parent[i]);
	}
	return 0;
}