#include <stdio.h>
#include <algorithm>
using namespace std;
int gox[4] = {0,0,1,-1 };
int goy[4] = {1,-1,0,0 };
bool visited[33][33];
double answer;
int n;
double point[4];
// 단순경로라함은 간곳은 방문하지않는다. 즉 사이클이 아니다.
void dfs(int x, int y, int depth, double po) {
	visited[x][y] = true;
	if (depth == n) {
		answer += po;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (!visited[nx][ny]) {
			dfs(nx, ny, depth + 1, po*point[i]);
			visited[nx][ny] = false; //갔다온곳을 해제해줘야하므로
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		scanf("%lf", &point[i]);
		point[i] /= 100;
	}
	dfs(15, 15, 0, 1.0);
	printf("%.9lf\n", answer);
	return 0;
}