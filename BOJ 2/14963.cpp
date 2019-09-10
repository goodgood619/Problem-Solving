#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int cnt[14];
// 2:4개 3:4개 .. 10:4개 근데 10이 4개(10은 16개) 11:4개
int main(){
	scanf("%d",&n);
	for (int i = 2; i <= 11; i++) {
		cnt[i] = 4;
		if (i == 10) cnt[i] = 16;
	}
	int sum = 0;
	int x = 0;
	for (int i = 1; i <= n; i++){
		int what;
		scanf("%d", &what);
		sum += what;
		cnt[what]--;
	}
	if (sum > 21) x = sum - 21;
	else x = 21 - sum;
	int smallcnt = 0;
	int bigcnt = 0;
	for (int i = 2; i <= 11; i++) {
		if (x >=i) {
			smallcnt += cnt[i];
		}
		else{
			bigcnt += cnt[i];
		}
	}

	if (bigcnt >=smallcnt)printf("DOSTA\n");
	else printf("VUCI\n");
	return 0;
}