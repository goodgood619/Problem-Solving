#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int T, A, B;
typedef pair <int, int>  P;
bool visited[5000005];
queue <P> q;
int value, Max;
void bfs() {
	q.push({ 0,1 });
	while (!q.empty()) {
		int value = q.front().first;
		int water = q.front().second;
		Max = max(Max, value);
		q.pop();
		int na = value + A;
		if (!visited[na] && na <= T) {
			visited[na] = true;
			q.push({ na,water });
		}
		int nb = value + B;
		if (!visited[nb] && nb <= T) {
			visited[nb] = true;
			q.push({ nb,water});
		}
		if (water > 0) {
			int nwater = value / 2;
			if (!visited[nwater] && nwater <= T) {
				visited[nwater] = true;
				q.push({ nwater,0 });
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &T, &A, &B);
	bfs();
	printf("%d\n", Max);
	return 0;
}