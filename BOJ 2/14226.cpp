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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,s;
bool visited[1101][1101];
int bfs(int display, int clip) {
	queue<pair<pair<int, int>,int>> q;
	q.push({{ display,clip }, 0});
	visited[display][clip] = true;
	int Min = 1e9;
	while (!q.empty()) {
		int dcnt = q.front().first.first;
		int ccnt = q.front().first.second;
		int time = q.front().second;
		q.pop();
		if (dcnt == s) return time;
		int temp = dcnt;
		if (!visited[dcnt][temp]) {
			visited[dcnt][temp] = true;
			q.push({ { dcnt,temp }, time + 1 });
		}
		if (ccnt > 0) {
			int temp2 = dcnt + ccnt;
			if (temp2<=1100 && !visited[temp2][ccnt]) {
				visited[temp2][ccnt] = true;
				q.push({ { temp2,ccnt }, time + 1 });
			}
		}
		if (dcnt > 0) {
			int temp2 = dcnt - 1;
			if (!visited[temp2][ccnt]) {
				visited[temp2][ccnt] = true;
				q.push({ {temp2,ccnt }, time + 1 });
			}
		}
	}
	return Min;
}
int main() {
	scanf("%d", &s);
	printf("%d\n",bfs(1, 0));
	return 0;
}