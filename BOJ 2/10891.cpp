#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
vector<vector<int>> a;
int path[100005];
int cyclecnt[100005];
int discover[100005];
bool visited[100005];
void go(int here, int down) {
	if (here == down) {
		cyclecnt[here]++;
		return;
	}
	else {
		go(path[here], down);
		cyclecnt[here]++;
	}
}
void dfs(int here, int high) {
	for (int i = 0; i < a[here].size(); i++) {
		int down = a[here][i];
		if (down != high) {
			if (discover[down] == 0) {
				discover[down] = discover[here] + 1;
				path[down] = here;
				dfs(down, here);
			}
			else if (discover[here] > discover[down]) {
				go(here, down);
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	discover[1] = 1;
	dfs(1, 0);
	bool check = false;
	for (int i = 1; i <= n; i++) {
		if (cyclecnt[i] >= 2) {
			check = true;
			break;
		}
	}
	if (check) printf("Not cactus\n");
	else printf("Cactus\n");
	return 0;
}