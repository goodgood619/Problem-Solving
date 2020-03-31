#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <queue>
#include <cstring>
using namespace std;
typedef int64_t ll;
int ans;
void boolclear(bool*& temp,int length) {
	for (int i = 0; i < length; i++) {
		temp[i] = false;
	}
}
struct p {
	int x, y;
	bool color;
};
bool flower[50][50];
int dist[50][50][2];
bool visit[50][50];
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
void makeFlower(vector<int>& red, vector<int>& green, int**& board, int r, int g,int n,int m) {
	memset(flower, false, sizeof(flower));
	memset(dist, 0, sizeof(dist));
	memset(visit, false, sizeof(visit));
	queue<p> q;

	for (auto here : red) {
		int x = here / m, y = here % m;
		q.push({ x,y,true });
		visit[x][y] = true;
	}
	for (auto here : green) {
		int x = here / m, y = here % m;
		q.push({ x,y,false });
		visit[x][y] = true;
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		bool color = q.front().color;
		q.pop();
		if (flower[x][y]) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i], ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 0) continue;
			if (!visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push({ nx, ny, color });
				int three = 0;
				if (!color) three = 1;
				dist[nx][ny][three] = dist[x][y][three] + 1;
				continue;
			}
			if (color) {
				if (dist[nx][ny][0] != 0) continue;
				int nexttime = dist[x][y][0] + 1;
				if (dist[nx][ny][1] == nexttime) {
					flower[nx][ny] = true;
				}
			}
			else {
				if (dist[nx][ny][1] != 0) continue;
				int nexttime = dist[x][y][1] + 1;
				if (dist[nx][ny][0] == nexttime) {
					flower[nx][ny] = true;
				}
			}
		}

	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (flower[i][j]) cnt++;
		}
	}
	ans = max(ans, cnt);
}
void chooseRed(int here, int cnt, int depth, vector<int>& v, vector<int>& temp, int g, int**& board,bool* &visited,int n,int m) {
	if (cnt == depth) {
		vector<int> green;
		for (int i = 0; i < v.size(); i++) {
			if (!visited[i]) {
				green.push_back(v[i]);
			}
		}
		makeFlower(temp, green, board, depth, g,n,m);
		green.clear();
		return;
	}
	for (int i = here; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			chooseRed(i + 1, cnt + 1, depth, v, temp, g, board, visited,n,m);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
void go(int here, int cnt, int depth, vector<int>& v, vector<int>& temp, bool*& visited, int g, int r, int**& board,int n,int m) {
	if (cnt == depth) {
		vector<int> v2;
		bool* rvisited = new bool[temp.size()];
		boolclear(rvisited, temp.size());
		chooseRed(0, 0, r, temp, v2, g, board, rvisited,n,m);
		delete[] rvisited;
		v2.clear();
		return;
	}
	for (int i = here; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			go(i + 1, cnt + 1, depth, v, temp, visited, g, r, board,n,m);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	int n,m,g,r;
	scanf("%d%d%d%d", &n, &m,&g,&r);
	int** board = new int*[n];
	for (int i = 0; i < n; i++) board[i] = new int[m];
	vector<int> v, temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 2) v.push_back(i * m + j);
		}
	}

	bool* visited = new bool[v.size()];
	boolclear(visited, v.size());
	go(0, 0, g + r, v, temp, visited, g, r, board,n,m);
	for (int i = 0; i < n; i++) delete[] board[i];
	delete[] board,visited;
	v.clear();
	temp.clear();
	printf("%d\n", ans);
	return 0;
}