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
int t, n, m;
char board[1005][1005] = { '\0', };
int dist[1005][1005] = { 0, };
bool visited[1005][1005] = { false, };
bool pvisited[1005][1005] = { false, };
int main() {
	scanf(" %d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(visited, false, sizeof(visited));
		memset(pvisited, false, sizeof(pvisited));
		memset(dist, 0, sizeof(dist));
		int sx = 0, sy = 0;
		queue<P> q; //불
		queue<P> sang; //상근
		swap(n, m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %c", &board[i][j]);
				if (board[i][j] == '@') {
					sx = i, sy = j;
					sang.push({ i,j });
					pvisited[i][j] = true;
				}
				else if (board[i][j] == '*') {
					q.push({ i,j });
					visited[i][j] = true;
				}
			}
		}

		//불을 퍼뜨린다(사람이 있든말든 이건 상관없다)
		// 사람이 이동한다(이동이 불가능하면 불가능하며, 탈출한다)
		// 만약 사람이 끝에 도달하면 나간다

		int no = 0;
		int yes = 0;
		int ans = 0;
		while (1) {
			queue<P> temp, stemp;//새로운 불위치
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + gox[i];
					int ny = y + goy[i];
					if (nx<1 || nx>n || ny<1 || ny>m) continue;
					if (board[nx][ny] == '#' || board[nx][ny] == '*' || visited[nx][ny]) continue;
					else if (!visited[nx][ny]) {
						visited[nx][ny] = true;
						board[nx][ny] = '*';
						temp.push({ nx,ny });
					}
				}
			}

			while (!sang.empty()) {
				int x = sang.front().first;
				int y = sang.front().second;
				if (x == n || x == 1 || y == 1 || y == m) {
					yes = 1;
					ans = dist[x][y];
					break;
				}
				sang.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + gox[i];
					int ny = y + goy[i];
					if (nx<1 || nx>n || ny<1 || ny>m) continue;
					if (board[nx][ny] == '#' || board[nx][ny] == '*' || visited[nx][ny]) continue;
					else if (!pvisited[nx][ny]) {
						pvisited[nx][ny] = true;
						stemp.push({ nx,ny });
						dist[nx][ny] = dist[x][y] + 1;
					}
				}
			}
			if (yes) {
				break;
			}
			if (stemp.empty()) {
				no = 1;
				break;
			}
			sang = stemp;
			q = temp;
		}
		no == 1 ? printf("IMPOSSIBLE\n") : printf("%d\n", ans + 1);
	}
	return 0;
}