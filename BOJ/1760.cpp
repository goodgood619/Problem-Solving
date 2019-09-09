#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int row[105][105];
int col[105][105];
bool visited[7500];
int n,m;
int path[7500];
int board[105][105];
vector<vector<int>> a;
int dfs(int here) {
	if (visited[here]) return 0;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (path[next] == -1 || dfs(path[next])) {
			path[next] = here;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d", &n, &m);
	a.resize(7500);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int rcnt = 1;
	int ccnt = 1;
	bool check = false;
	for (int i = 1; i <= n; i++){
		check = false;
		for (int j = 1; j <= m; j++){
			if (board[i][j] == 1){
				continue;
			}
			else if (board[i][j] == 2){
				if (!check){
					check = true;
					rcnt++;
				}
				else continue;
			}
			else if (board[i][j] == 0){
				if (check) check = false;
				row[i][j] = rcnt;
				continue;
			}
		}
		rcnt++;
	}
	check = false;
	for (int j = 1; j <= m; j++) {
		check = false;
		for (int i = 1; i <= n; i++) {
			if (board[i][j] == 1) {
				continue;
			}
			else if (board[i][j] == 2){
				if (!check){
					check = true;
					ccnt++;
				}
				continue;
			}
			else if (board[i][j] == 0){
				if (check) check = false;
				col[i][j] = ccnt;
				continue;
			}
		}
		ccnt++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 0) {
				a[row[i][j]].push_back(col[i][j]);
			}
		}
	}

	memset(path, -1, sizeof(path));
	int ok = 0;
	for (int i = 1; i < a.size();i++){
		if (a[i].size() == 0) continue;
		memset(visited, false, sizeof(visited));
		ok+=dfs(i);
	}
	printf("%d\n", ok);
	return 0;
}