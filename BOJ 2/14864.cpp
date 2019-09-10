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
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
int n, m;
int arr[100005];
vector<int> v;
bool visited[100005];
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) arr[i] = i;
	for (int i = 1; i <= m; i++) {
		int win, lose;
		scanf("%d%d", &win, &lose);
		arr[win]++, arr[lose]--;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[arr[i]]) {
			visited[arr[i]] = true;
			v.push_back(arr[i]);
		}
		else {
			printf("-1\n");
			return 0;
		}
	}

	for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
	return 0;
}