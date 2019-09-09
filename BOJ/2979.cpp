#include <stdio.h>
int A, B, C,ans,cnt;
int start[3][100];
int main() {
	scanf("%d%d%d", &A, &B, &C);
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		for (int j= u; j<v; j++)
			start[k][j] = 1;
		k++;
	}
	int p = 0;
	for (int i = 0;p<100;) {
		if (start[i][p]!=0){
			cnt++;
		}
		if (i == 2)
		{
			if (cnt == 1) ans += (A*1);
			if (cnt == 2) ans += (B*2);
			if (cnt == 3) ans += (C*3);
			cnt = 0;
			p++;
			i = 0;
			continue;
		}
			i++;
	}
	printf("%d\n", ans);
	return 0;
}