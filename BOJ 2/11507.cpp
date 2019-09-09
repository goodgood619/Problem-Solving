#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char c[1010];
bool card[4][14];
int cnt[4];
bool good;
int main() {
	for (int i = 0; i < 4; i++)
		cnt[i] = 13;
	scanf("%s", c);
	for (int i = 0; i < strlen(c);) {
		if (c[i] == 'P')
		{
			int x = c[i + 1] - '0';
			int y = c[i + 2] - '0';
			if (card[0][10*x + y] == true)
				good=true;
			card[0][10*x + y] = true;
			i += 3;
			continue;
		}
		if (c[i] == 'K') {
			int x = c[i + 1] - '0';
			int y = c[i + 2] - '0';
			if (card[1][10*x + y] == true)
				good=true;
			card[1][10*x + y] = true; 
			i += 3;
			continue;
		}
		if (c[i] == 'H') {
			int x = c[i + 1] - '0';
			int y = c[i + 2] - '0';
			if (card[2][10*x + y] == true)
				good=true;
			card[2][10*x + y] = true;
			i += 3;
			continue;
		}
		if (c[i] == 'T') {
			int x = c[i + 1] - '0';
			int y = c[i + 2] - '0';
			if (card[3][10*x + y] == true)
				good=true;
			card[3][10*x + y] = true;
			i += 3;
			continue;
		}
	}

	for (int i = 0; i <= 3; i++) {
		for (int j = 1; j <= 13; j++) {
			if (good)
			{
				printf("GRESKA\n");
				break;
			}
			if (card[i][j] == true)
				(cnt[i])--;
		}
		if (good)
			break;
	}
	if(!good)
	printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
	return 0;
}