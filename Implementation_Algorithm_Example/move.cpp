#include <cstdio>
#include <algorithm>

using namespace std;

pair<int,int> move(int x, int y, int d, int s,int n) {
	for (int i = 0; i < s; i++) {
		int nx = x + gox[d];
		int ny = y + goy[d];
		if (nx < 0) {
			nx += n;
		}
		if (nx >= n) {
			nx -= n;
		}
		if (ny < 0) {
			ny += n;
		}
		if (ny >= n) {
			ny -= n;
		}
		x = nx;
		y = ny;
	}
	return { x,y };
}

int main(){
  

  return 0;
}
