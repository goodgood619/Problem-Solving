#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int t,n;
bool lose[15];
int main(){
	scanf("%d", &t);
	while (t--){
		string robot[15];
		memset(lose, false, sizeof(lose));
		int win = 0;
		int idx = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			char c[35] = { '\0', };
			scanf("%s", c);
			robot[i] = c;
		}
		// S:가위 R:바위 P:보
		int length = robot[1].size();
		for (int i = 0; i < length; i++){
			int scnt = 0;
			int rcnt = 0;
			int pcnt = 0;
			for (int j = 1; j <= n; j++){
				if (lose[j]) continue;
				if (robot[j][i] == 'S') scnt++;
				else if (robot[j][i] == 'R') rcnt++;
				else if (robot[j][i] == 'P') pcnt++;
			}
			if (scnt >= 1 && rcnt >= 1 && pcnt >= 1) continue;
			else if (scnt == 0 && rcnt >= 1 && pcnt >= 1) {
				for (int j = 1; j <= n; j++) {
					if (robot[j][i] == 'S' || robot[j][i]=='P') continue;
					else if (robot[j][i] == 'R') {
						lose[j] = true;
					}
				}
			}
			else if (scnt >= 1 && rcnt == 0 && pcnt >= 1) {
				for (int j = 1; j <= n; j++) {
					if (robot[j][i] == 'S' || robot[j][i] == 'R') continue;
					else if (robot[j][i] == 'P') {
						lose[j] = true;
					}
				}
			}
			else if (scnt >= 1 && rcnt >= 1 && pcnt == 0) {
				for (int j = 1; j <= n; j++) {
					if (robot[j][i] == 'R' || robot[j][i] == 'P') continue;
					else if (robot[j][i] == 'S') {
						lose[j] = true;
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (!lose[i]){
				idx = i;
				win++;
			}
			else continue;
 		}
		if (win >= 2) printf("0\n");
		else if (win == 1) printf("%d\n", idx);
	}
	return 0;
}