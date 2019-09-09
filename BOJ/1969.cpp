#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cstring>
int n, m,k;
char c[1000][50];
int alphabet[26];
int Maxcnt,cnt;
char q[50];
char cc;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &c[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = c[j][i] - 'A';
			alphabet[cnt]++;
		}
		//alphabet갯수세어주기
		for (int i = 0; i < 26; i++) {
			if (Maxcnt < alphabet[i])
			{
				Maxcnt = alphabet[i];
				cc = i + 'A';
			}
		}
		q[k++] = cc;
		Maxcnt = 0;
		memset(alphabet, 0, sizeof(alphabet));
	}
	//됏고 그다음에 갯수만구해주면됨
	printf("%s\n", q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] != q[j])
				cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}