#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
int arr[1001][1001];
int visited[1001][1001];
int M, N;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int flag = 0;
void bfs(int y, int x) {
	queue <pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		visited[r][c] = 1;
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k], nc = c + dc[k];
			if (0 <= nr && nr < M && 0 <= nc && nc < N&& arr[nr][nc] == 0 && visited[nr][nc] == 0){
				visited[nr][nc] = 1;
				q.push(make_pair(nr, nc));
			}
		}
	}
}
int main() {
	scanf("%d %d", &M, &N);
	string s;
	for (int i = 0; i < M; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		if (arr[0][i] == 0 && visited[0][i] == 0)
			bfs(0, i);
	}
	for (int i = 0; i < N; i++) {
		if (visited[M - 1][i] == 1) flag = 1;
	}
	if (flag == 1)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}