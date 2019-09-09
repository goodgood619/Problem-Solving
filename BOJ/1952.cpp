#include <cstdio>
#include <algorithm>
using namespace std;
int n, m,cnt,real;
bool visited[101][101];
//이동방향:동남서북
// 끝까지 이동해서 막힌경우
// 가다가 이미 방문을 해서 막힌경우
//끝지점이 꺾이냐 안꺾이냐그거 봐야겠네
int main() {
	scanf("%d%d", &n, &m);
	int total = n*m;
	int currentx = 1;
	int currenty = 1;
	visited[currentx][currenty] = true;
	cnt++;
	while (1) {
		if (cnt == total) break;
		for (int j = currenty+1; j <= m; j++) {
			if (visited[currentx][j]){
				break;
			}
			else {
				visited[currentx][j] = true;
				cnt++;
				currenty += 1;
			}
		}
		real++;
		if (cnt == total) break;
		for (int i= currentx+1; i <= n; i++) {
			if (visited[i][currenty]) {
				break;
			}
			else {
				visited[i][currenty] = true;
				cnt++;
				currentx += 1;
			}
		}
		real++;
		if (cnt == total) break;

		for (int j = currenty-1; j>=1; j--) {
			if (visited[currentx][j]) {
				break;
			}
			else {
				visited[currentx][j] = true;
				cnt++;
				currenty-=1;
			}
		}
		real++;
		if (cnt == total) break;

		for (int i = currentx-1; i>=1; i--) {
			if (visited[i][currenty]) {
				break;
			}
			else {
				visited[i][currenty] = true;
				cnt++;
				currentx-= 1;
			}
		}
		real++;
		if (cnt == total) break;
	}
	printf("%d\n", real-1);
	return 0;
}