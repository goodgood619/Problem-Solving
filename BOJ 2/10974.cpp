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
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,1,-1,1,-1 };
int n;
vector<int> v;
bool visited[10];
void go(int cnt, int depth) {
	if (cnt == depth) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			go(cnt + 1, depth);
			v.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d", &n);
	go(0, n);
	return 0;
}