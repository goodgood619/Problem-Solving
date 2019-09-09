#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
	for (int a = 1; a <= 100; a++) {
		int aim = a*a*a;
		bool ok = false;
		int aa = 0;
		int bb = 0;
		int cc = 0;
		for (int x = 2; x <= 100; x++) {
			for (int y = x+1; y <= 100; y++) {
				for (int z = y+1; z <= 100; z++) {
					int what = x*x*x + y*y*y + z*z*z;
					if (aim == what) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a,x,y,z);
					}
					else if (aim<what) break;
				}
			}
		}

	}
	return 0;
}