#include <stdio.h>
#include <algorithm>
#include <string.h>
char s[11];
using namespace std;
int main(){
	scanf("%s", s);
	int length = strlen(s);
	sort(s, s + length);
	for (int i = length - 1; i >= 0; i--) {
		printf("%c", s[i]);
	}
	return 0;
}