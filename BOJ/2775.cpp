#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int t, k, n;
int floo[16][16];
// a 층의 b 호에 살려면 자신의 아래(a - 1)층에 1호부터 b 호까지 사람들의 수의 합만큼 사람들을 데려와 살아야한다
int main(){
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k); //k층에
		scanf("%d", &n); //n호
		memset(floo, 0, sizeof(floo));
		for (int i = 1; i <=n; i++) {
			floo[0][i] = i;
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				for (int p = 1; p <= j; p++) {
					floo[i][j] += floo[i - 1][p];
				}
			}
		}
		printf("%d\n", floo[k][n]);
	}
	return 0;
}