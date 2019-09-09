#include <stdio.h>
#include <algorithm>
using namespace std;
int M, N, K,cnt,ans;
int main() {
	scanf("%d%d%d", &N, &M, &K);
	int women = K;
	int p = N;
	int q = M;
	for (int i = 0; i <= K; i++) {
		N -= women;
		M -= i;
		//여기서 팀만들수있는지 보고
		while (1) {
			if (N <= 0 || M <= 0) break;
			else if(N>=2 && M>=1){
				N -= 2;
				M -= 1;
				cnt++;
			}
			else break;
		}
		ans=max(cnt, ans);
		//다시 초기화
		N = p;
		M = q;
		women--;
		cnt = 0;
	}
	printf("%d\n", ans);
	return 0;
}