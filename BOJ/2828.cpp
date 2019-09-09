#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m,j,cnt;
int apple[21];
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d", &j);
	for (int i = 1; i <= j; i++) {
		scanf("%d", &apple[i]);
	}
	int idx = 1;
	for (int i = 1; i <= j; i++){
		int spot = apple[i];
		bool check = false;
		bool check2 = false;
		bool check3 = false;
		bool check4 = false;
		if (idx <= spot) {
			for (int k = idx; k <= n; k++) {
				for (int p = k; p < k + m; p++) {
					if (p>n) { check2 = true; break; }
					if (spot == p){
						idx = k;
						check = true;
						break;
					}
					else continue;
				}
				if (check) break;
				else if (!check2) cnt++;
			}
		}
		else {
				for (int q = idx; q >= 1; q--) {
					for (int p = q; p < q + m; p++){
						if (p > n) { check4 = true; break; }
						if (spot == p) {
							idx = q;
							check3 = true;
							break;
						}
						else continue;
					}
					if (check3) break;
					else if(!check4)cnt++;
				}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
