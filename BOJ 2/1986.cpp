#include <cstdio>
#include <cstdint>
#include <string>
#include <set>
#include <queue>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
int gox[8] = { -2,-2,-1,-1,1,1,2,2 };
int goy[8] = { 1,-1,2,-2,2,-2,1,-1 };
int gox2[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy2[8] = { 1,0,0,-1,1,-1,1,-1 };
bool check[1000000];
struct pp {
	int x, y;
};
void bfs(int n, int m, queue<pp>& t, bool**& pexist, bool**& qexist, bool**& kexist) {
	while (!t.empty()) {
		int x = t.front().x;
		int y = t.front().y;
		t.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + gox[i], ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || pexist[nx][ny] || qexist[nx][ny] || kexist[nx][ny]) continue;
			check[nx * n + ny] = true;
		}
	}
}
void bfs2(int n, int m, queue<pp>& t, bool**& pexist, bool**& qexist, bool**& kexist) {
	while (!t.empty()) {
		int x = t.front().x;
		int y = t.front().y;
		t.pop();
		for (int i = 0; i < 8; i++) {
			int tx = x, ty = y;
			while (true) {
				int nx = tx + gox2[i], ny = ty + goy2[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || pexist[nx][ny] || kexist[nx][ny] || qexist[nx][ny]) break;
				check[nx * n + ny] = true;
				tx = nx, ty = ny;

			}
		}
	}
}
int main() {
	Int n, m, q, k, p, cnt = 0;
	scanf("%d%d%d", &n, &m, &q);
	bool** pexist = new bool* [n], ** qexist = new bool* [n], ** kexist = new bool* [n];
	for (int i = 0; i < n; i++) {
		pexist[i] = new bool[m], qexist[i] = new bool[m], kexist[i] = new bool[m];
	}
	queue<pp> qok, kok;
	for (int i = 0; i < q; i++) {
		Int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		qok.push({ x,y });
		qexist[x][y] = true;
		check[n * x + y] = 1;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		Int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		kok.push({ x,y });
		kexist[x][y] = true;
		check[n * x + y] = 1;
	}
	scanf("%d", &p);
	for (int i = 0; i < p; i++) {
		Int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		pexist[x][y] = true;
		check[n * x + y] = 1;
	}
	bfs(n, m, kok, pexist, qexist, kexist);
	bfs2(n, m, qok, pexist, qexist, kexist);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i * n + j]) continue;
			else cnt++;
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) {
		delete[] pexist[i], qexist[i], kexist[i];
	}
	delete[] pexist, qexist, kexist;
	return 0;
}