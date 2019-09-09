#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
int t, n;
int temp[17];
int loop[1200][17];
int arr[17];
int main(){
	scanf("%d", &t);
	while(t--){
		int p = 1;
		bool check = false;
		bool ok = false;
		int cnt = 0;
		memset(loop, 0, sizeof(loop));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]);
		loop[p][i] = arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0) cnt++;
		}
		if (cnt == n) printf("ZERO\n");
		else {
			cnt = 0;
			while (1){
				int loopcnt = 0;
				cnt = 0;
				if (ok)break;
				for (int i = 1; i <= n; i++) {
					if (i == n) {
						temp[i] = abs(arr[i] - arr[1]);
					}
					else temp[i] = abs(arr[i] - arr[i + 1]);
				}
				p++;
				for (int i = 1; i <= n; i++) {
					loop[p][i] = temp[i];
				}
				for (int i = 1; i <= n; i++) {
					arr[i] = temp[i];
					if (arr[i] == 0) cnt++;
				}
				if (cnt == n) {
					check = true;
					break;
				}
				for (int i = 1; i <p; i++) {
					loopcnt = 0;
					for (int j = 1; j <= n; j++) {
						if (arr[j] == loop[i][j]) loopcnt++;
						else continue;
					}
					if (loopcnt == n) {
						ok = true;
						break;
					}
				}
			}
			if (check) printf("ZERO\n");
			else if (ok) printf("LOOP\n");
		}
	}
	return 0;
}