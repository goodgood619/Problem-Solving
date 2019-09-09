#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,real;
int dicecnt[7];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int idx = 0;
		int idy = 0;
		int Max2 = 0;
		int Max = 0;
		int M = 0;
		memset(dicecnt, 0, sizeof(dicecnt));
		for (int j = 1; j <= 4; j++){
			int a;
			scanf(" %d", &a);
			dicecnt[a]++;
		}
		for (int i = 1; i <= 6; i++) {
			M=max(dicecnt[i], M);
		}
		if (M > 1) {
			for (int i = 1; i <= 6; i++) {
				int cnt = dicecnt[i];
				if (cnt == 0 || cnt<M) continue;
				if (Max <= cnt) {
					if (Max != 0) {
						Max2 = cnt;
						idy = i;
						continue;
					}
					Max = cnt;
					idx = i;
				}
			}
			if (Max == 4) {
				real=max(real,50000 + idx * 5000);
			}
			else if (Max == 3) {
				real=max(real,10000 + idx * 1000);
			}
			else if (Max == 2 && Max2 == 0) {
				real = max(real, 1000 + idx * 100);
			}
			else if (Max == 2 && Max2 == 2) {
				real = max(real,2000+idx * 500 + idy * 500);
			}
		}
		else {
			int total = 0;
			int MM = 0;
			for (int i = 1; i <= 6; i++) {
				if (total<=dicecnt[i]) {
					total = dicecnt[i];
					MM = i;
				}
			}
			real=max(real,MM * 100);
		}
	}
	printf("%d\n", real);
	return 0;
}