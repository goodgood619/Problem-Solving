#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char c[103];
char temp[103];
int k;
int main(){
	scanf("%s", c);
	int length = strlen(c);
	temp[k++] = c[0];
	for (int i = 1; i < length; i++) {
		if (c[i] == '-') {
			temp[k++]=c[i + 1];
		}
		else continue;
	}
	for (int i = 0; temp[i] != '\0'; i++)
		printf("%c", temp[i]);
	return 0;
}