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
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,1,-1,1,-1 };
int board[500][500];
int n, m;
int parent[250005];
int Size[250005];
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
	Size[v] += Size[u];
	Size[u] = 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int i = 0; i < n*m; i++) {
		Size[i] = 1;
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int dir = -1;
			int Min = board[i][j];
			for (int k = 0; k < 8; k++) { //여기서 갈곳을 정한다
				int nx = i + gox[k];
				int ny = j + goy[k];
				if (nx < 0 || nx >= n || ny<0 || ny >= m || board[i][j]<=board[nx][ny]) continue;
				else if (board[i][j] > board[nx][ny]) {
					if (Min > board[nx][ny]) {
						Min = board[nx][ny];
						dir = k;
					}
				}
			}
			if (dir == -1) continue;
			else {
				int nx = i + gox[dir];
				int ny = j + goy[dir];
				int here = i * m + j,next=nx*m+ny;
				uni(here, next);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Size[i*m + j] == 0) printf("0 ");
			else printf("%d ", Size[i*m + j]);
		}
		printf("\n");
	}

	return 0;
}