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
typedef pair<pair<int, int>, pair<int, bool>> PPP;
int t, n,k;
int gox[3] = {-1,1,2};
vector<vector<int>> board;
bool visited[200005];
void bfs(int here) {
	queue<P> q;
	q.push({ here,0 });
	visited[here] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		if (here == k){
			printf("%d\n", cnt);
			return;
		}
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 2) {
				int nx = here * gox[i];
				if (!visited[nx] && nx >= 0 && nx <= 100000) {
					visited[nx] = true;
					q.push({ nx,cnt + 1 });
				}
			}
			else {
				int nx = here + gox[i];
				if (!visited[nx] && nx >= 0 && nx <= 100000) {
					visited[nx] = true;
					q.push({ nx,cnt + 1 });
				}
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &k);
	bfs(n);
	return 0;
}