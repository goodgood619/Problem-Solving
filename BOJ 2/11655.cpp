#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char s[104];
int smallalpha[27];
int main(){
	scanf("%[^\n]s", s);
	int length = strlen(s);
	for (int i = 0; i < 26; i++) {
		smallalpha[i] = 'a' + i;
	}

	for (int i = 0; i < length; i++) {
		char c = s[i];
		if (c >= 'A' && c <= 'Z') {
			c += 13;
			if (c > 90) {
				c = c % 90 + 64;
				s[i] = c;
				continue;
			}
			s[i] = c;
		}
		else if (c >= 'a'&& c <= 'z') {
			int num = c- 'a';
			num += 13;
			num %= 26;
			s[i] = smallalpha[num];
		}
	}
	printf("%s\n", s);
	return 0;
}