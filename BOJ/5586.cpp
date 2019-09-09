#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int joicnt,ioicnt;
char c[10005];
int main(){
	scanf("%s", c);
	int length = strlen(c);
	for (int i = 0; i < length-2; i++) {
		if (c[i] == 'O') continue;
		else {
			if (c[i] == 'J' && c[i + 1] == 'O' && c[i + 2] == 'I') {
				joicnt++;
				continue;
			}
			else if (c[i] == 'I' && c[i + 1] == 'O' && c[i + 2] == 'I') {
				ioicnt++;
				continue;
			}
		}
	}
	printf("%d\n", joicnt);
	printf("%d\n", ioicnt);
	return 0;
}