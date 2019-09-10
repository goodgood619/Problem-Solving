#include <stdio.h>
#include <queue>
using namespace std;

int r, c, n;
char map[201][201];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct pt {
	int x, y;
};
queue<pt> q;

bool safe(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}

void printres(char a[201][201]) {
	for (int i = 0; i < r; i++) {
		printf("%s\n", a[i]);
	}
}

void bomb() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'O') {
				q.push({ i, j });
			}
			else {
				map[i][j] = 'O';
			}
		}
	}

	while (!q.empty()) {
		pt cur = q.front();
		q.pop();

		map[cur.x][cur.y] = '.';
		for (int j = 0; j < 4; j++) {
			int nx = cur.x + dx[j];
			int ny = cur.y + dy[j];

			if (!safe(nx, ny)) continue;
			map[nx][ny] = '.';
		}
	}
}

int main() {

	scanf("%d %d %d", &r, &c, &n);

	for (int i = 0; i < r; i++) {
		scanf("%s", map[i]);
	}

	if (n == 1) {
		printres(map);
	}

	else if (n % 2 == 0) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("O");
			}
			printf("\n");
		}
	}

	else {
		bomb();
		if (n % 4 == 1) {
			bomb();
		}
		printres(map);
	}

	return 0;
}