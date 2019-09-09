#include <stdio.h>
int main(void) {
	int white[100][100] = { 0 };
	int num, x, y;
	int cnt = 0;
	scanf("%d", &num);
	for (int t = 0; t < num; t++) {
		scanf("%d %d", &x, &y);
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				white[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (white[i][j] == 1)
				cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}