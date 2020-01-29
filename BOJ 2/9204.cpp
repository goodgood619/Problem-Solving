#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <vector>
typedef int32_t Int;
typedef int64_t ll;
using namespace std;
int gox[4] = {1,1,-1,-1};
int goy[4] = {1,-1,-1,1};
struct p {
	int y;
	int x;
};
void go(int cnt,int depth,int sx,int sy,int ex,int ey,vector<p> &v,bool &check,int dx,int dy) {
	if (check) return;
	if (sx == ex && sy == ey) {
		check = true;
		printf("%d %c %d ", cnt,dy+'A',8-dx);
		for (int i = 0; i < v.size(); i++) {
			printf("%c %d ", v[i].y + 'A', 8-v[i].x);
		}
		printf("\n");
		return;
	}
	if (cnt == depth) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 8; j++) {
			int nx = sx + j * gox[i], ny = sy + j * goy[i];
			if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
			v.push_back({ ny,nx });
			go(cnt + 1, depth, nx, ny, ex, ey, v, check,dx,dy);
			v.pop_back();
		}
	}

}
int main() {
	Int t;
	scanf("%d", &t);
	while (t--) {
		int sx;
		char sy;
		int ex;
		char ey;
		scanf(" %c %d %c %d", &sy, &sx, &ey, &ex);
		sx = 8 - sx,ex = 8-ex;
		sy -= 'A', ey -= 'A';
		sy = (int)sy;
		ey = (int)ey;
		vector<p> v;
		bool check = false;
		go(0, 4,sx,sy,ex,ey,v,check,sx,sy);
		if (!check) printf("Impossible\n");
		v.clear();
	}
	return 0;
}