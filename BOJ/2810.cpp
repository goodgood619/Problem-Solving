#include <stdio.h>
#include <algorithm>
#include <string.h>
char c[51];
char temp[200];
int n,cnt;
int main() {
	scanf("%d", &n);
	scanf("%s", c);
	temp[0] = '*';
	int k = 1;
	for (int i = 0; i < n;) {
		if (c[i] == 'S') {
			temp[k++] = 'S';
			temp[k++] = '*';
			i++;
			continue;
		}
		else if (c[i] == 'L') {
			temp[k++] = 'L';
			temp[k++] = 'L';
			temp[k++] = '*';
			i += 2;
			continue;
		}
	}

	for (int i = 0; temp[i] != '\0'; i++) {
		if (temp[i] == '*') cnt++;
	}
	if (n == 1) printf("1\n");
	else if(cnt<=n)printf("%d\n", cnt);
	else if (cnt > n) printf("%d\n", n);
	return 0;
}