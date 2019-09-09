#include <cstdio>
#include <algorithm>
using namespace std;
int a[50003];
int b[50003];
int n, x, y, cnt;
int main() {
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= x; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= y; i++) {
		scanf("%d", &b[i]);
	}
	sort(a + 1, a + x + 1);
	sort(b + 1, b + y + 1);
	int aptr = 1;
	int bptr = 1;
	bool check = false;
	bool fir = false;
	while (1) {
		if (aptr > x || bptr > y) break;
		if (a[aptr] < b[bptr]){
			if (!fir) { fir = true;
			aptr++;
			check = false;
			continue;
			}
			if (fir) {
				if (!check) {
					aptr++;
					continue;
				}
				else {
					check = false;
					cnt++;
					aptr++;
					continue;
				}
			}
		}
		else if (a[aptr] > b[bptr]){
			if (!fir) {
				fir = true;
				bptr++;
				check = true;
				continue;
			}
			if (fir) {
				if (check) {
					bptr++;
					continue;
				}
				else {
					check = true;
					cnt++;
					bptr++;
					continue;
				}
			}
		}
		else if (a[aptr] == b[bptr]){
			aptr++;
			bptr++;
			continue;
		}
	}
	if (aptr > x && bptr<=y) {
		if (!check) cnt++;
	}
	if (bptr > y && aptr<=x) {
		if (check) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}