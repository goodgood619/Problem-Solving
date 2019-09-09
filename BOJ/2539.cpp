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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m,paper,moja;
vector<P> v;
bool check(int mid) {
	bool visited[1005] = { false, };
	int use = 1;
	for (int i = 0; i < v.size(); i++) {
		if (visited[i]) continue;
		int sx = v[i].first;
		int sy = v[i].second;
		if (sy > mid) return false; //그냥 처음 y좌표값이 애초에 mid보다 클때는 불가능
		visited[i] = true;
		for (int j = i; j < v.size(); j++) {
			int nx = v[j].first;
			int ny = v[j].second;
			if (visited[j]) continue;
			if (nx <= sx + mid-1 && ny <= mid) {
				visited[j] = true;
			}
			else if (nx >= sx + mid) {
				use++;
				break;
			}
			else if (ny > mid) return false;
		}
	}
	if (use > paper) return false;
	else return true;
}
int main() {
	scanf("%d%d", &n,&m);
	scanf("%d", &paper);
	scanf("%d", &moja);
	for (int i = 1; i <= moja; i++) {
		int x, y;
		scanf("%d%d", &y, &x);
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	int left = 1;
	int right = 2000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d\n",left);
	return 0;
}