#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int t, cnt;
char s[22];
int main(){
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &cnt, s);
		int length = strlen(s);
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < cnt; j++) {
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}