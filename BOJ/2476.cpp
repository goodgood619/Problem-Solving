#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,real;
int cnt[7];
int main(){
	scanf("%d", &t);
	while (t--){
		int Cnt = 0;
		int idx = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 3; i++){
			int a;
			scanf("%d", &a);
			cnt[a]++;
		}
		for (int i = 1; i <= 6; i++) {
			if (Cnt <=cnt[i]) {
				Cnt = cnt[i];
				idx = i;
			}
		}
		if (Cnt == 3) {
			real=max(real,10000 + idx * 1000);
		}
		else if (Cnt == 2) {
			real=max(real,1000 + idx * 100);
		}
		else if (Cnt == 1) {
			real = max(real, idx * 100);
		}
	}
	printf("%d\n", real);
	return 0;
}