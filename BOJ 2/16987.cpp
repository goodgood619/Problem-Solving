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
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int n,Max;
vector<P> v;
bool visited[15];
void dfs(int index,int cnt) {
	if (index == n) {
		Max = max(Max, cnt);
		return;
	}
	int check = 0;
	if (v[index].first <= 0) { // 지금 들고 있는 계란이 부셔져있다면, 아래의 경우는 실행할수가 없다. 부서졌으니까
		dfs(index + 1, cnt);
	}
	for (int i = 0; i < n; i++) { // index로 부셔야함
		if (v[index].first<=0 || index == i || v[i].first <= 0) continue;
		v[i].first -= v[index].second;
		v[index].first -= v[i].second;
		int temp = cnt;
		if (v[i].first <= 0) temp++;
		if (v[index].first <= 0) temp++;
		dfs(index + 1, temp);
		v[index].first += v[i].second;
		v[i].first += v[index].second;
	}
	Max = max(Max, cnt); // 더이상 깰게 없다, 그때의 깬갯수를 저장함
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back({ a,b });
	}
	dfs(0,0);
	printf("%d\n", Max);
	return 0;
}