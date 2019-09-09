#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[1001];
char answer[1001];
int main() {
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		char a = s[i];
		if (a == 'A')
			answer[i] = 'X';
		else if (a == 'B')
			answer[i] = 'Y';
		else if (a == 'C')
			answer[i] = 'Z';
		else
		answer[i] = a - 3;
	}
	printf("%s\n", answer);
	return 0;
}