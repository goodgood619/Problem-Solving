#include <cstdio>
#include <algorithm>
using namespace std;
// 북 동 남 서(1 1 2 2 3 3 4 4 5 5 )
int gox[4] = {0,1,0,-1};
int goy[4] = {1,0,-1,0};
int startx, starty;
int n;
int main(){
	scanf("%d", &n);
	int cnt = 0;
	int hab = 1;
	bool check = false;
	while (cnt != n){
		for (int i = 0; i < 2; i++){
			for (int j = 1; j <= hab; j++){
				int nx = startx + gox[i];
				int ny = starty + goy[i];
				cnt++;
				startx = nx;
				starty = ny;
				if (cnt == n) {
					check = true;
					break;
				}
			}
			if (check) break;
		}
		if (check) break;
		hab++;
		for (int i = 2; i < 4; i++) {
			for (int j = 1; j <= hab; j++) {
				int nx = startx + gox[i];
				int ny = starty + goy[i];
				cnt++;
				startx = nx;
				starty = ny;
				if (cnt == n) {
					check = true;
					break;
				}
			}
			if (check) break;
		}
		if (check) break;
		hab++;
	}
	printf("%d %d\n", startx, starty);
	return 0;
}
