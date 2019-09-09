#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char s[105];
int main(){
	scanf("%s", s);
	bool check = true;
	int length = strlen(s);
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		if (s[i] == s[j]) {
			check = true;
		}
		else {
			check = false; break;
		}
	}
	if (check) printf("1\n");
	else printf("0\n");
	return 0;
}