#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int t,n,m,tempkey,ans;
char board[105][105];
bool visited[105][105];
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
typedef pair<pair<int, int>, int> P;
queue <P> q;
// 문의갯수+1회만큼 열쇠를 다먹고, 그때 문서를 얻을수있는지 없는지를 계속돌린다. 비트마스킹으로 열쇠를 다 먹어서 체킹함
void bfs(int x, int y,int keytotal,bool check){
	visited[x][y] = true;
	q.push({ {x,y },keytotal });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curkey = q.front().second;
		tempkey = max(tempkey,curkey);
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<0 || nx>n + 1 || ny<0 || ny>m + 1 || visited[nx][ny] || board[nx][ny] == '*') continue;
			else if (board[nx][ny]>='A' && board[nx][ny]<='Z'){
				int ok = curkey & (1 << board[nx][ny] - 'A');
				if (ok != 0) {
					visited[nx][ny] = true;
					q.push({ {nx,ny },curkey });
				}
			}
			else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
				int earnkey = curkey | (1 << board[nx][ny] - 'a');
				visited[nx][ny] = true;
				q.push({ {nx,ny },earnkey });
			}
			else if(board[nx][ny]=='$'){
				if (!check) {
					visited[nx][ny] = true;
					q.push({ {nx,ny },curkey });
				}
				else {
					visited[nx][ny] = true;
					q.push({ {nx,ny }, curkey });
					ans++;
				}
			}
			else if (board[nx][ny] == '.') {
				visited[nx][ny] = true;
				q.push({{nx,ny},curkey });
			}
		}
	}
}
int main(){
	scanf("%d", &t);
	while (t--) {
		memset(visited, false, sizeof(visited));
		char key[30] = { '\0', };
		int doorcnt = 0;
		scanf("%d%d", &n, &m);
		tempkey = 0;
		int real = 0;
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				board[i][j] = '.';
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++){
				scanf(" %c", &board[i][j]);
				if (board[i][j] >= 'A' && board[i][j] <= 'Z')doorcnt++;
			}
		}
		scanf("%s", key);
		int length = strlen(key);
		int keytotal = 0;
		for (int i = 0; i < length; i++) {
			if (key[i] == '0') continue;
			else keytotal=keytotal | (1 << key[i] - 'a');
		}
		bool check = false;
		for (int i = 1; i <= doorcnt+1; i++){
			memset(visited, false, sizeof(visited));
			if (check) {
				keytotal = tempkey;
			}
			ans = 0;
			bfs(0, 0, keytotal, false);
			memset(visited, false, sizeof(visited));
			bfs(0, 0, tempkey, true);
			real = max(ans, real);
			check = true;
		}
		printf("%d\n", real);
	}
	return 0;
}