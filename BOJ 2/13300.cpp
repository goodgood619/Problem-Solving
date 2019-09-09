#include <stdio.h>
#include <algorithm>
using namespace std;
int n, k,cnt;
int age[7][2]; //학년* 성별
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int S, Y;
		scanf("%d%d", &S, &Y);
		age[Y][S]++;
	}

	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j <= 1; j++) {
			if (age[i][j]>0 && age[i][j] <= k) cnt++;
			else if (age[i][j] == 0) continue;
			else if (age[i][j] > k) {
				int plus = age[i][j] / k;
				int plus2 = age[i][j] % k;
				if(plus2==0)
				cnt += plus;
				else {
					cnt += plus;
					cnt += 1;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}