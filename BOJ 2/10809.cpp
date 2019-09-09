#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;
int alpha[26];
char c[101];
int cnt;
int main() {
	memset(alpha, -1, sizeof(alpha));
	scanf("%s", c);

	for (int i = 0; i < strlen(c); i++) {
		int a = c[i]-97;
		if(alpha[a]==-1)alpha[a]=cnt;
		cnt++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alpha[i]);
	}
	return 0;
}