#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
char c[55];
char idcnt[27];
int cnt[27];
int rever[55];
int idx=-1;
int idx2;
int j;
int Cnt;
int Cnt2;
void go(int length) {
	for (int i = 0; i < strlen(c); i++)
		cnt[c[i] - ('A' - 1)]++;
	for (int i = 1; i <= 26; i++) {
		if (cnt[i] == 0) continue;
		idcnt[i] = 'A' + (i - 1);
	}
}
int main() {
	scanf("%s", c);
	int length = strlen(c);
	go(length);
	for (int i = 1; i <= 26; i++)
	{
		if (cnt[i] % 2) {
			idx = i;
			Cnt++;
		}
	}
	if (Cnt >= 2) {
		printf("I'm Sorry Hansoo\n");
		return 0;
	}
	Cnt = 0;
	for (int i = 1; i <= 26; i++) {
		if (idx == i) {
			cnt[i]--;
		}
		for (j = 1; j <= cnt[i] / 2; j++)
			printf("%c", i-1 + 'A');
		for (; j <= cnt[i]; j++)
			rever[Cnt++] = i-1;
	}
	if (idx >= 0)
		printf("%c", idx-1 + 'A');
	for (int k = Cnt; k > 0; k--)
		printf("%c", rever[k-1] + 'A');
	printf("\n");
	return 0;
}