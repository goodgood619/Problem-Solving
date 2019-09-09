#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;
char c[1000001];
int alpha[26];
int Max;
bool check;
char q;
int main(){
	scanf("%s", c);
	for (int i = 0; i < strlen(c); i++) {
		char s = c[i];
		if (c[i] >= 'A' && c[i] <= 'Z') {
			int a = c[i] -65;
			alpha[a]++;
		}
		else if (c[i] >= 'a' && c[i] <= 'z') {
			int b = c[i] - 97;
			alpha[b]++;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (Max < alpha[i]) {
			Max = alpha[i];
			q = i + 65;
			check = false;
		}
		else if (Max == alpha[i]) {
			check = true;
		}
	}
	if (check) printf("?\n");
	else printf("%c\n", q);
	return 0;
}