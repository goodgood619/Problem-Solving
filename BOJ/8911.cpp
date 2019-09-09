#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;
bool visited[1004][1004];
int t;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(visited, false, sizeof(visited));
		int startx = 500;
		int starty = 500;
		int start = 0;
		int idx = 0;
		int idy = 0;
		int Midx = 2000;
		int Midy = 2000;
		char s[503] = { '\0', };
		scanf("%s", s);
		int length = strlen(s);
		visited[startx][starty] = true;
		idx = max(idx, startx);
		idy = max(idy, starty);
		Midx = min(Midx, startx);
		Midy = min(Midy, starty);
		for (int i = 0; i<length; i++) {
			char c = s[i];
			if (c == 'F') {
				int nextx = startx + gox[start];
				int nexty = starty + goy[start];
				if (!visited[nextx][nexty]) {
					visited[nextx][nexty] = true;
				}
				startx = nextx;
				starty = nexty;
				idx = max(idx, startx);
				idy = max(idy, starty);
				Midx = min(Midx, startx);
				Midy = min(Midy, starty);
			}
			else if (c == 'B') {
				if (start % 2 == 0){
					int p = start;
					if (p== 0) p = 2;
					else if (p == 2) p = 0;
					int nextx = startx + gox[p];
					int nexty = starty + goy[p];
					if (!visited[nextx][nexty]) {
						visited[nextx][nexty] = true;
					}
					startx = nextx;
					starty = nexty;
					idx = max(idx, startx);
					idy = max(idy, starty);
					Midx = min(Midx, startx);
					Midy = min(Midy, starty);
				}
				else if (start % 2 == 1) {
					int p = start;
					if (p== 1) p= 3;
					else if (p == 3) p = 1;
					int nextx = startx + gox[p];
					int nexty = starty + goy[p];
					if (!visited[nextx][nexty]) {
						visited[nextx][nexty] = true;
					}
					startx = nextx;
					starty = nexty;
					idx = max(idx, startx);
					idy = max(idy, starty);
					Midx = min(Midx, startx);
					Midy = min(Midy, starty);
				}
			}
			else if (c == 'L') {
				if (start == 0) {
					start = 3;
				}
				else {
					start -= 1;
				}
			}
			else if (c == 'R') {
				start = (start + 1) % 4;
			}
		}

		printf("%d\n", (idx - Midx)*(idy - Midy));
	}
	return 0;
}